#include "assembler.h"

Assembler::Assembler(const std::string& inputFileName) : fileName(inputFileName) 
{
    run();
}

// run the assembler
void Assembler::run() 
{
    ErrorHandling error("../input/" + fileName + ".asm"); 
    // Check for errors in source file
    if (error.errorHandling()) 
    {
        firstPass(); 
        secondPass(); 
    } 
    else
    {
        std::cout << "The file is not correct.\n";
    }
}

void Assembler::firstPass() 
{
    std::ifstream file("../input/" + fileName + ".asm");
    if(!file.is_open())
	{
		throw std::runtime_error("Not able to open file: " + fileName);
	}
    std::string line;
    int lc = 0; // Location counter

    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        std::string word;
        iss >> word;

        if (word == "ORG") 
        {
            iss >> lc; // Set location counter from ORG 
            continue;
        }

        if (!iss) continue; // Skip empty lines

        // Detect labels
        if (word.back() == ',') 
        {
            std::string symbol = word.substr(0, word.size() - 1);
            symbolTable[symbol] = lc; // Store label and its location in symbolTable
            iss >> word;
        }

        lc++;
    }
}

void Assembler::secondPass() 
{
    std::ifstream file("../input/" + fileName + ".asm");
    if(!file.is_open())
	{
		throw std::runtime_error("Not able to open file: " + fileName);
	}

    std::string line;
    int lc = 0;

    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        std::string opcode;
        std::string hexCode;
        std::string operand;
        iss >> opcode;

        if (opcode == "END") 
        {
            break; // Stop processing on END directive
        }

        if (opcode == "ORG") 
        {
            iss >> lc; // Set location counter from ORG directive
            continue;
        }

        if (opcode.back() == ',') 
        {
            opcode = opcode.substr(0, opcode.size() - 1); 
            if (symbolTable.find(opcode) != symbolTable.end()) 
            {
                int value = symbolTable[opcode];
                std::stringstream ss;
                ss << std::hex << value;
                hexCode += ss.str();
            } 
            else 
            {
                errorInLine("Undefined symbol " + operand, lc); 
                continue;
            }
            iss >> opcode;
        }

        // Process MRI and Non-MRI instructions
       
        int findnum = OpcodeTables::findOpcode(opcode);
        bool isMRI = findnum == 0; // Check if opcode is MRI
        bool isNON_MRI = findnum == 1; // Check if opcode is NON-MRI

        if (isMRI) 
        {
            iss >> operand;
            
            if (iss.eof()) 
            {
                hexCode = OpcodeTables::getMRIOperand(opcode);
            } 
            else 
            {
                std::string addressingType;
                iss >> addressingType;
                if (addressingType == "I") // Indirect addressing
                {
                    hexCode = OpcodeTables::getMRIOperandI(opcode);
                }
                else 
                {
                    errorInLine("Unknown addressing mode!", lc); 
                    continue; 
                }
            }

            // Resolve symbolic operands
            if (symbolTable.find(operand) != symbolTable.end()) 
            {
                int value = symbolTable[operand];
                std::stringstream ss;
                ss << std::setw(3) << std::setfill('0') << std::hex << value;
                hexCode += ss.str();
            } 
            else 
            {
                errorInLine("Undefined symbol " + operand, lc); 
                continue;
            }
            machineCode.insert({lc, hexCode}); 
        } 
        else if(isNON_MRI)
        {
            // Process Non-MRI opcodes
            int nonMRIValue = OpcodeTables::getNON_MRIOperand(opcode);
            if (nonMRIValue != -1) 
            {
                std::stringstream ss;
                ss << std::hex << nonMRIValue;
                machineCode.insert({lc, ss.str()});
            } 
            else 
            {
                errorInLine("Unknown opcode " + opcode, lc); 
            }
        } 
        else 
        {
            if(iss.eof())
            {
                errorInLine("no value for parameter. ", lc);
                continue;
            }
            iss >> operand;
            if(opcode == "HEX")
            {
                std::stringstream ss;
                ss << std::hex << operand;
                machineCode.insert({lc, ss.str()});
            }
            else if(opcode == "DEC")
            {
                std::stringstream ss;
                ss << operand;
                machineCode.insert({lc, ss.str()});
            }
        }
        lc++;
    }

    // Write output machine code to file
    outputWriter("../output/" + fileName + ".out");
}

std::string hexToBinary16(const std::string& hex) {
    unsigned int decimalValue;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> decimalValue;

    std::bitset<16> binaryValue(decimalValue);

    return binaryValue.to_string();
}

void Assembler::outputWriter(const std::string& outputPath) 
{
    std::ofstream outputFile(outputPath);
    if (!outputFile) 
    {
        errorInLine("Unable to open output file");
        return;
    }
    for (const auto& pair : machineCode) 
    {
        outputFile << std::setw(4) << std::setfill('0') << pair.first << " | " 
        << std::setw(4) << std::setfill('0') <<  pair.second << " | ";
        outputFile << hexToBinary16(pair.second) << "\n"; 
    }
    outputFile.close();
}

void Assembler::errorInLine(const std::string& message, int line)
{ 
	std::cerr << message << "(Line " << line << ")\n";
}	

void Assembler::errorInLine(const std::string& message)
{ 
	std::cerr << message << "\n";
}	