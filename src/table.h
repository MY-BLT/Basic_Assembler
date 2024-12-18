#ifndef TABLES_H
#define TABLES_H

#include <map>
#include <string>
#include <vector>

class OpcodeTables {
public:
    OpcodeTables();
    
    std::string getMRIOperand(const std::string& opcode);
    int getNonMRIOperand(const std::string& opcode);
    std::vector<std::string> getPseudoInstructions();

private:
    std::map<std::string, std::vector<std::string>> MRI;    
    std::map<std::string, int> NON_MRI;                   
    std::vector<std::string> PSEUDO_INSTRUCTIONS;        
};

#endif

