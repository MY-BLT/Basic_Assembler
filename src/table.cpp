#include "table.h"

std::map<std::string, std::vector<std::string>> OpcodeTables::MRI;
std::map<std::string, int> OpcodeTables::NON_MRI;
std::vector<std::string> OpcodeTables::INSTRUCTION;

OpcodeTables::OpcodeTables()
{
MRI = {
        {"AND", {"0", "8"}},
        {"ADD", {"1", "9"}},
        {"LDA", {"2", "A"}},
        {"STA", {"3", "B"}},
        {"BUN", {"4", "C"}},
        {"BSA", {"5", "D"}},
        {"ISZ", {"6", "E"}}
    };
    
    NON_MRI = {
        {"CLA", 0x7800},
        {"CLE", 0x7400},
        {"CMA", 0x7200},
        {"CIR", 0x7080},
        {"CIL", 0x7040},
        {"INC", 0x7020},
        {"SPA", 0x7010},
        {"SNA", 0x7008},
        {"SZA", 0x7004},
        {"SZE", 0x7002},
        {"HLT", 0x7001},
        {"INP", 0xF800},
        {"OUT", 0xF400},
        {"SKI", 0xF200},
        {"SKO", 0xF100},
        {"ION", 0xF080},
        {"IOF", 0xF040}
    };

    INSTRUCTION = {"ORG", "HEX", "DEC", "END"};
}

int OpcodeTables::findOpcode(const std::string& opcode)
{
    OpcodeTables tb;
    if(MRI.find(opcode) != MRI.end())
    {
        return 0; // MRI
    }
    else if(NON_MRI.find(opcode) != NON_MRI.end())
    {
        return 1; // NON_MRI
    }
    return -1; // Not found
}

std::string OpcodeTables::getMRIOperand(const std::string& opcode)
{
    if(MRI.find(opcode) != MRI.end())
    {
        return MRI[opcode][0];
    }
    return "";
}

std::string OpcodeTables::getMRIOperandI(const std::string& opcode)
{
    if(MRI.find(opcode) != MRI.end())
    {
        return MRI[opcode][1];
    }
    return "";
}

int OpcodeTables::getNON_MRIOperand(const std::string& opcode)
{
    if(NON_MRI.find(opcode) != NON_MRI.end())
    {
        return NON_MRI[opcode];
    }
    return -1;
}

std::vector<std::string> OpcodeTables::getInstruction()
{
    return INSTRUCTION;
}
