#include "FileSystem.h"
#include <iostream>
#include <string>
#include <ctime>
#include <regex>

	FileSystem::FileSystem()
{
	this->prompt = CommandPrompt();
	this->tree = FileSystemTree();
}



void FileSystem::printCommandPrompt()
{
	//std::cout << "katherine@katherine-pc:~$";
	std::cout << prompt;
}

void FileSystem::startApplication()
{
	while (true)
	{
		printCommandPrompt();
		std::string inputCommand;
		std::cin >> inputCommand;

		if(std::regex_match(inputCommand, std::regex("pwd")))
		{
			getAbsolutePath();
		}

		if (std::regex_match(inputCommand, std::regex("ls")))
		{
			getCurrentDirectoryContent();
		}

	}
}


void FileSystem::getAbsolutePath()
{
	prompt.printWorkingDirectory();
}

void FileSystem::getDirectoryContent(std::string name)
{
}

void FileSystem::makeDirectory(Directory currDir, std::string name)
{
}

void FileSystem::removeDirectory(std::string name)
{
}

void FileSystem::changeDirectory(std::string name)
{
}


void FileSystem::getCurrentDirectoryContent()
{
	getFilesFromDirectory(currentDirectory);
}


void FileSystem::getFilesFromDirectory(const Directory& directory)
{
	if (tree.existsDirectory(directory))
	{
		tree.getFileNames(directory);
	}
}

int main()
{
	FileSystem system;
	system.startApplication();

	return 0;
}
