#include<error.h>

ErrorHandling::ErrorHandling(const std::string& filename)
{
	this->filename = filename;
	this->errorHandling();
}

bool ErrorHandling::errorHandling()
{
	std::ifstream file("./output/" + filename);
	if(!file.is_open())
	{
		throw std::runtime_error("Not able to open file: " + filename);
	}

	std::string line;
	std::vector<bool> isTrue = {false, false, false, false};
	int lineNum = 0;
	
	if(isTrue[1])
	{
		std::istringstream iss(line);
		std::string part;
		std::vector<std::string> parts;

		while(iss >> part)
			parts.push_back(part);
	}

	while(std::getline(file, line))
	{
		lineNum++;
		
		isTrue[0] = checkEnd();
		isTrue[1] = checkOrg();
		isTrue[2] = checkOrgAdd();
	        isTrue[3] = checkOrgLimit();
	}
	if(!isTrue[1])
		errorInLine("No ORG.", lineNum);

	return isTrue[0] && isTrue[1] && isTrue[2] && isTrue[3];
	
	inline bool checkEnd()
	{
		std::string lastLine;
		while(std::getline(file, lastLine)) {}
		file.clear();
		file.seekg(0);

		if(lastLine == "END")
		{
			return true;
		}
		errorInLine("No END.", lineNum);
		return false;
	}
	inline bool checkOrg()
	{
		if(line.find("ORG") != std::string::npos)
		{
			return true;
		}
		return false;

	}

	inline bool checkOrgAdd()
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

	}
	bool checkOrgLimit()
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
			}else
				return true;
		}
	}
}	

void ErrorHandling::errorInLine(std::string message, int line)
{ 
	std::cerr << message << "(Line " << line << "\n";
}	




