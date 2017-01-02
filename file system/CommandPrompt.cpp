#include "CommandPrompt.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const CommandPrompt& obj)
	{
		os << obj.ownerName
			<< obj.separator
			<< obj.computerName;
		std::list<std::string> copy = obj.workingDirectory;
		for (std::list<std::string>::iterator iterator = copy.begin(); iterator != copy.end(); ++iterator)
		{
			os << *iterator;
		}
			os << obj.userRightsShowingSymbol << " ";

		return os;
	}

void CommandPrompt::printWorkingDirectory()
{
	if (workingDirectory.size() == 1)
	{
		std::cout << "/" << std::endl;
		return;
	}

	for (std::list<std::string>::iterator iterator = workingDirectory.begin(); iterator != workingDirectory.end(); ++iterator)
	{
		if (*iterator == "~")
		{
			std::cout << "/";
		}
		std::cout << *iterator;
	}
	std::cout << std::endl;
}
