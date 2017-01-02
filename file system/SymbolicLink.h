#pragma once
#include "Directory.h"

class SymbolicLink : public File
{
private:
	Directory *dir;
public:
	
	virtual bool isRegularFile();
	virtual bool isDirectory();
	virtual bool isSymbolicLink();
};
