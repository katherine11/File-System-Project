#pragma once
#include <string>

class File
{
protected:
	size_t i_node;
	std::string name;
	long size;//in bytes;
	char *lastAccessTime;
	char *lastContentChangeTime;
	char *lastMetaDataChangeTime;
public:
	virtual bool isRegularFile();
	virtual bool isDirectory();
	virtual bool isSymbolicLink();
	
};
