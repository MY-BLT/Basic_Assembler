#include "assembler.h"
#include "table.h"

Assembler::Assembler(const std::string& inputFileName)
{
	this->fileName = inputFileName;
	run();
}

void Assembler::run()
{
	if(ErrorHandling error(fileName)); // check the error of code
	{
		firstPass(); //for finding symbols and fill out symbolTable
		secondPass(); //for converting codes to binary in ram
	}
}

void Assembler::firstPass()
{
	std::ifstream file.open("./input/" + fileName);
	if(!file.is_open())
	{
		std::cerr << "Unable to open file\n";
		return;
	}

	std::string line;
	int lc = 0; //location counter

	while(std::getLine(file, line))
	{
		std::istringstream iss(line);
		std::string word;
		iss >> word;

		if(word == "ORG")
		{
			iss >> std::hex >> lc;
			continue;
		}

		if(!iss) continue; //nothing read!

		//find labels=>
		if(word.back() == ',')
		{
			std::string symbol =  word.substr(0, word.size() - 1);
			symbolTable[symbol] = lc;
			iss >> word; //clear iss and get all
		}

		lc++; // go to the next line
	}
}

void Assembler::secondPass()
{
	std::ifstream file.open("./input/" + fileName);
	
	std::string line;
	int lc = 0;

	while(std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string opcode;
		iss >> opcode;

		if(opcode == "END")
		{
			break;
		}

		if(opcode == "ORG")
		{
			iss >> std::hex >> lc;
			continue;
		}

		if(opcode.back() == ',')
		{
			opcode = opcode.substr(0, opcode.size() - 1);
		}

		// in this block i should seprate MRI and NonMRI instructions then make the machine code:>
		if(OpcodeTables::findOpcode(opcode) == 0)
		{
			std::string hexCode;
			std::string symbol;
			std::string addressT;

			iss >> symbol;

			if(iss.eof())
			{
				hexCode = OpcodeTables::getMRIOperand(opcode);
			}
			else if(iss >> addressT)	
			{
				if(addressT == I)
				{
					hexCode = OpcodeTables::getMRIOperandI(opcode);
				}
				else
				{
					//error
				}
			}
			
				
			if(symbolTable.find(symbol) != symbolTable.end())
			{
				int value = symbolTable[symbol];

				std::stringstream ss;
				ss << std::hex << value;
				
				hexCode += ss.str();
			}
			else
			{
				//error
			}
		
		}

	}


}

