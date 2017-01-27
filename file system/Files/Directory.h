#ifndef FILE_SYSTEM_PROJECT_DIRECTORY_H
#define FILE_SYSTEM_PROJECT_DIRECTORY_H

#include <ostream>
#include "File.h"
#include "../Structures/Vector.hpp"

class Directory : public File
{
private:
    static int dirsCount;
    bool isRoot;
    Vector<File*> filesInCurrentDirectory;
    virtual void copy(const Directory &directory);
    virtual void destroy();
public:
    Directory();
    Directory(std::string name);
    Directory(std::string name, long size, Vector<File*> files);
    Directory(const Directory & directory);
    Directory & operator=(const Directory & directory);
    virtual ~Directory();

    bool isRootDirectory();
    virtual bool isRegularFile();
    virtual bool isDirectory();
    virtual bool isSymbolicLink();

    friend std::ostream &operator<<(std::ostream &os, const Directory &directory);

    void deleteFile(File *file);
    void addFile(File *file);

    Vector<File*> & getFilesInCurrentDirectory();
};

#endif //FILE_SYSTEM_PROJECT_DIRECTORY_H
