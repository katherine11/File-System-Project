#include "SymbolicLink.h"

bool SymbolicLink::isRegularFile()
{
	return false;	
}

bool SymbolicLink::isDirectory()
{
	return false;
}

bool SymbolicLink::isSymbolicLink()
{
	return true;
}