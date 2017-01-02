#pragma once
#include "Directory.h"
#include <string>
#include "FileSystemTree.h"
#include "CommandPrompt.h"


class FileSystem
{
private:
	FileSystemTree tree;
	CommandPrompt prompt;
	Directory currentDirectory;
	void printCommandPrompt();
public:

	FileSystem();

	void startApplication();
	void getAbsolutePath();
	void getFilesFromDirectory(const Directory& directory);
	void getCurrentDirectoryContent();
	void getDirectoryContent(std::string name);
	void makeDirectory(Directory currDir, std::string name);
	void removeDirectory(std::string name);
	void changeDirectory(std::string name);
};
