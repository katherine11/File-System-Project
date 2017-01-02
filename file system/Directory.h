#pragma once
#include "File.h"
#include <list>

class Directory : public File
{
private:
	bool isRoot;
	std::list<File> filesInCurrentDirectory;
public:
	bool isRootDirectory();
	virtual bool isRegularFile();
	virtual bool isDirectory();
	virtual bool isSymbolicLink();
	friend bool operator==(const Directory &dir1, const Directory &dir2);
};
