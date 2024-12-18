#ifndef ERRORS_H
#define ERRORS_H

#include<fstream>
#include<stdexcept>
#include<vector>

class ErrorHandling
{
	public:
		ErrorHandling(const std::string& filename);
		bool errorHandling();
		void errorInLine(std::string message, int line);
	private:
		std::string filename;
};
#endif
