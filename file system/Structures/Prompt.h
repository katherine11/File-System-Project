#ifndef FILE_SYSTEM_PROJECT_PROMPT_H
#define FILE_SYSTEM_PROJECT_PROMPT_H

#include <string>
#include <list>
#include <iostream>
#include "Vector.hpp"

class Prompt
{
    std::string ownerName;
    std::string computerName;
    char separator;//default separator between username and hostname;
    Vector<std::string> workingDirectory;// default working directory;
    char userRightsShowingSymbol;//if not logged as a superuser;

public:

    Prompt();
    Prompt(std::string ownerName, std::string computerName);

    friend std::ostream& operator<<(std::ostream& os, Prompt& obj);

    void printWorkingDirectory();

    void cleanWorkingDirectory();

    void addDirectory(std::string directoryName);

    void deleteLastDirectory();
};



#endif //FILE_SYSTEM_PROJECT_PROMPT_H
