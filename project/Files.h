#pragma once
#include <iostream>
using namespace std;

enum FileType
{
	REGULAR_FILE,
  DIRECTORY_FILE,
  SYMBOLIC_LINK
};

// abstract class
class File
{
	private:
  	string name;
  	int fileID;
  	double size;
  	FileType fileType;
  	char* accessTime;
  	char* contentModificationTime;
  	char* metadataModificationTime;
  public:
     File(string name, double, int);
  	 File(const File& other);
  	 File& operator=(const File& other);
     ~File();
  	 void renameFile();
};

class RegularFile : public File
{
  private:
		string extension;
  	string content;
  public:
  	RegularFile(string, int, double, FileType, string extension, string content); 
		RegularFile(const RegularFile &other);
  	RegilarFile &operator=(const RegularFile & other);
  	~RegularFile();
};

class Directory : public File
{
  public:
  	Directory(string, int, double, FileType);
  	Directory(const Directory & directory);
  	Directory &operator=(const Directory & directory);
  	~Directory();	
  	string getAbsolutePath();
};

class SymbolicLink : public File
{
  private:
  	File* link;
};
