#pragma once
#include <string>
#include <ostream>
#include <list>

//const char SEPARATOR_VALUE_I = '@';
//char DEFAULT_USER_RIGHTS_SYMBOL_I = '$';
//std::string ROOT_DIRECTORY_SIGN_I = "~";

class CommandPrompt
{
	std::string ownerName;
	std::string computerName;
	char separator;//default separator between username and hostname;
	std::list<std::string> workingDirectory;// default working directory;
	char userRightsShowingSymbol;//if not logged as a superuser;
	
public:

	CommandPrompt()
	{
		this->ownerName = "katherine";
		this->computerName = "katherine-pc";
		separator = '@';
		workingDirectory.push_back("~");
		userRightsShowingSymbol = '$';
		//separator = SEPARATOR_VALUE_I;
		//workingDirectory = ROOT_DIRECTORY_SIGN_I;
		//userRightsShowingSymbol = DEFAULT_USER_RIGHTS_SYMBOL_I;		
	}

	CommandPrompt(std::string ownerName, std::string computerName)
	{
		this->ownerName = ownerName;
		this->computerName = computerName;
		separator = '@';
		workingDirectory.push_back("~");
		userRightsShowingSymbol = '$';//	separator = SEPARATOR_VALUE_I;
	//	workingDirectory = ROOT_DIRECTORY_SIGN_I;
	//	userRightsShowingSymbol = DEFAULT_USER_RIGHTS_SYMBOL_I;		
	}

	friend std::ostream& operator<<(std::ostream& os, const CommandPrompt& obj);

	void printWorkingDirectory();
};
