#include "Directory.h"

bool Directory::isRootDirectory()
{
	return this->isRoot;
}

bool Directory::isRegularFile()
{
	return false;
}

bool Directory::isDirectory()
{
	return true;
}

bool Directory::isSymbolicLink()
{
	return false;
}

bool operator==(const Directory& dir1, const Directory& dir2)
{
	return dir1.name == dir2.name;
}
