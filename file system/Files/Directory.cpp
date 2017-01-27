#include <cstring>
#include "Directory.h"

std::string DEFAULT_USERNAME = "katerina";
std::string DEFAULT_HOME_DIR = "home";
std::string DEFAULT_SEP = "/";

int Directory::dirsCount = 0;

Directory::Directory() : File(){

    if(dirsCount == 0)
    {
        isRoot = true;
        name = DEFAULT_SEP + DEFAULT_HOME_DIR + DEFAULT_SEP + DEFAULT_USERNAME;
    }
    else
    {
        isRoot = false;
        name = "";
    }
    dirsCount++;
}

Directory::Directory(std::string name) : File(name) {
    if(name.find(DEFAULT_SEP) != std::string::npos)
    {
        std::cout << "Unallowed symbols used in the name!";
        this->name = "";
    }
    this->isRoot = false;
}

Directory::Directory(std::string name, long size, Vector<File*> files) : File(name, size){
    this->isRoot = isRoot;
    if(isRoot){
        name = DEFAULT_SEP + DEFAULT_HOME_DIR + DEFAULT_SEP + DEFAULT_USERNAME;
    }
    this->filesInCurrentDirectory = files;
}

Directory::Directory(const Directory &directory) : File(directory){
    copy(directory);
}

Directory::~Directory() {
    destroy();
}

Directory &Directory::operator=(const Directory &directory) {
    if(this != &directory)
    {
        destroy();
        File::operator=(directory);
        copy(directory);
    }
    return *this;
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

bool Directory::isRootDirectory()
{
    return this->isRoot;
}

void Directory::destroy() {
    File::destroy();
    for (int index = 0; index < filesInCurrentDirectory.getSize(); ++index) {
        delete filesInCurrentDirectory.getAt(index);
    }
    filesInCurrentDirectory.clear();
}

void Directory::copy(const Directory &directory) {
    isRoot = directory.isRoot;
    filesInCurrentDirectory = directory.filesInCurrentDirectory;
}

Vector<File*> &Directory::getFilesInCurrentDirectory()  {
    return this->filesInCurrentDirectory;
}


void Directory::deleteFile(File *file) {

    if(filesInCurrentDirectory.containsElement(file))
    {
        filesInCurrentDirectory.deleteElement(file);
    }
}

void Directory::addFile(File *file) {
    if(!filesInCurrentDirectory.containsElement(file))
    {
        filesInCurrentDirectory.pushBack(file);
    }
}

std::ostream &operator<<(std::ostream &os, const Directory &directory) {
    os << static_cast<const File &>(directory) << " isRoot: " << directory.isRoot << " filesInCurrentDirectory: "
       << directory.filesInCurrentDirectory;
    return os;
}
