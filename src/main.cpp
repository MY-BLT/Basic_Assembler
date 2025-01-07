#include "assembler.cpp"
#include <iostream>
#include <fstream>

int main()
{
    std::cout << "Enter the fileName:\n";
    std::string filename;
    std::cin >> filename;
    std::fstream file;
    
    Assembler assembler(filename);
    return 0;
}