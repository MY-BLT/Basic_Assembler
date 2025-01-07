#ifndef ERRORS_H
#define ERRORS_H

#include <fstream>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <sstream>

class ErrorHandling 
{
public:
    ErrorHandling(const std::string& filename);
    bool errorHandling();

private:
    std::string filename;
    std::fstream file;
    int lineNum = 0;
    std::vector<std::string> parts;
    std::vector<bool> isTrue{false, false, false, false};
    
    bool checkEnd(std::string lastLine);
    bool checkOrg(const std::string& line);
    bool checkOrgAdd();
    bool checkOrgLimit();
    void errorInLine(const std::string& message, int line);
};

#endif // ERRORS_H
