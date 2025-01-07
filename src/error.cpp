#include "error.h"

ErrorHandling::ErrorHandling(const std::string& filename)
{
	this->filename = filename;
	this->file.open(filename);
	
}


bool ErrorHandling::checkEnd(std::string lastLine)
{
	if(lastLine == "END")
	{
		return true;
	}
	errorInLine("No END." + lastLine, lineNum);
	return false;
}
bool ErrorHandling::checkOrg(const std::string& line)
{
	if(line.find("ORG") != std::string::npos)
	{
		std::istringstream iss(line);
		std::string part;
		parts.clear();
		while(iss >> part)
			parts.push_back(part);
		isTrue[1] = true; // ORG is available in the file
		isTrue[2] = checkOrgAdd();
		isTrue[3] = checkOrgLimit();
		return true;
	}
	else if(!isTrue[1])
	{
		return false;
	}
	return isTrue[1];
}

bool ErrorHandling::checkOrgAdd()
{
	if(isTrue[1])
	{

		if(parts.size() == 2)
		{
			return true;
		}
		errorInLine("No ORG value.", lineNum);
		return false;
	}
	return false;
}
bool ErrorHandling::checkOrgLimit()
{
	if(isTrue[1] && isTrue[2])
	{
		int orgValue = std::stoi(parts[1], nullptr, 16);
		if(orgValue > 0xFFFF)
		{
			errorInLine("ORG value upper.", lineNum);
			return false;
		}
		else if(orgValue < 0)
		{
			errorInLine("ORG value lower.", lineNum);
			return false;
		}
		return true;
	}
	return false;
}

bool ErrorHandling::errorHandling()
{
	if(!file.is_open())
	{
		throw std::runtime_error("Not able to open file: " + filename);
	}

	std::string line;

	while(std::getline(file, line))
	{
		lineNum++;
		
		isTrue[1] = checkOrg(line);
	}

	isTrue[0] = checkEnd(line);
	std::cout << "error checking: " << isTrue[0] << ' ' << isTrue[1] << ' ' << isTrue[2] << ' ' << isTrue[3] << '\n';
	return isTrue[0] && isTrue[1] && isTrue[2] && isTrue[3];
	
}	

void ErrorHandling::errorInLine(const std::string& message, int line)
{ 
	std::cerr << message << "(Line " << line << ")\n";
}	




