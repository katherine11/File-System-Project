#include "Prompt.h"
#include <iostream>

const char SEPARATOR_VALUE = '@';
const char DEFAULT_USER_RIGHTS_SYMBOL = '$';
const std::string DEFAULT_ROOT = "~";
const std::string DEFAULT_USERNAME = "katherine";
const std::string DEFAULT_PC_NAME = "katherine-pc";

Prompt::Prompt()
{
    this->ownerName = DEFAULT_USERNAME;
    this->computerName = DEFAULT_PC_NAME;
    separator = SEPARATOR_VALUE;
    userRightsShowingSymbol = DEFAULT_USER_RIGHTS_SYMBOL;
}

Prompt::Prompt(std::string ownerName, std::string computerName)
{
    this->ownerName = ownerName;
    this->computerName = computerName;
    separator = SEPARATOR_VALUE;
    workingDirectory.pushBack(DEFAULT_ROOT);
    userRightsShowingSymbol = DEFAULT_USER_RIGHTS_SYMBOL;
}

std::ostream& operator<<(std::ostream& os, Prompt& obj)
{

    os << obj.ownerName
       << obj.separator
       << obj.computerName;
    obj.printWorkingDirectory();
    os << DEFAULT_ROOT;
    os << obj.userRightsShowingSymbol << " ";

    return os;
}
void Prompt::printWorkingDirectory()
{
    for (int index = 0; index < workingDirectory.getSize(); ++index) {
        if(workingDirectory.getAt(index) != "~")
        {
            std::cout << "/";
        }
        std::cout << workingDirectory.getAt(index);
    }
}

void Prompt::cleanWorkingDirectory() {

    workingDirectory.clear();

}

void Prompt::addDirectory(std::string directoryName) {
    this->workingDirectory.pushBack(directoryName);
}

void Prompt::deleteLastDirectory() {
    size_t index = this->workingDirectory.getSize() - 1;
    this->workingDirectory.deleteAt(index);
}
