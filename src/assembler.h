#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "error.cpp"
#include "table.cpp"
#include <bitset>
/** 
 * this class is the main class for basic assembler
 * @author MYasin
*/
class Assembler 
{
public:
    Assembler(const std::string& inputFileName);
private:
    /** 
     * run is for using first and second pass in class
     * @see firstPass() for first pass
     * @see secondPass() for second pass
    */
    void run();
    // First pass for finding symbols
    void firstPass();
    // Second pass for converting instructions to machine code
    void secondPass();
    std::string intToBinary(int value, int bits);
    void outputWriter(const std::string& outputPath);
    void errorInLine(const std::string& message);
    void errorInLine(const std::string& message, int line);

    std::string fileName;
    std::unordered_map<std::string, int> symbolTable;
    std::map<int, std::string> machineCode; // Store generated machine codes for output
};

#endif // ASSEMBLER_H
