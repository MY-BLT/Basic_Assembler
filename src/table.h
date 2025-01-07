#ifndef TABLES_H
#define TABLES_H

#include <map>
#include <string>
#include <vector>

class OpcodeTables {
public:
    OpcodeTables();
    
    static int findOpcode(const std::string& opcode);
    static std::string getMRIOperand(const std::string& opcode);
    static std::string getMRIOperandI(const std::string& opcode);
    static int getNON_MRIOperand(const std::string& opcode);
    static std::vector<std::string> getInstruction();

private:
    static std::map<std::string, std::vector<std::string>> MRI;
    static std::map<std::string, int> NON_MRI;
    static std::vector<std::string> INSTRUCTION;
};

#endif
