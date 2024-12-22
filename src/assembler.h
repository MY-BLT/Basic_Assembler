#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

class Assembler 
{
	public:
		void run(const std::string fileName);
		Assembler(const std::string inputFileName);
	private:
		void firstPass();
		void secondPass();
		std::string intToBinary(int value, int bits);
		void outputWriter(const std::string& path, const std::unordered_map<std::string, int>& output);
		
		std::string fileName;
		std::unordered_map<std::string, int> symbolTable;
};
#endif
