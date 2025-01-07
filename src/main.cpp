#include "assembler.cpp"
#include <iostream>
#include <fstream>

int main()
{
    std::cout << "Enter the fileName:\n";
    std::string filename;
    std::cin >> filename;
    std::fstream file;

    // filename = "../input/"+filename;

    // file.open(filename);

    // if(!file.is_open())
    // {
    //     std::cout << "the file is not open.\n";
    //     return 1;
    // }
    // std::string line;

    // while(std::getline(file, line))
    // {
    //     std::cout << line << '\n';
    // }
    
    Assembler assembler(filename);
    return 0;
}