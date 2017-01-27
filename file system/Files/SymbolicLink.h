#ifndef FILE_SYSTEM_PROJECT_SYMBOLICLINK_H
#define FILE_SYSTEM_PROJECT_SYMBOLICLINK_H

#include "File.h"
#include "Directory.h"

class SymbolicLink : public File
{
private:
    Directory *dir;
    void copy(const SymbolicLink &link);
    void destroy();
public:

    SymbolicLink();
    SymbolicLink(std::string name, Directory *directory);
    SymbolicLink(std::string name, long size, Directory *directory);
    SymbolicLink(const SymbolicLink &link);
    SymbolicLink &operator=(const SymbolicLink &link);
    virtual ~SymbolicLink();

    virtual bool isRegularFile();
    virtual bool isDirectory();
    virtual bool isSymbolicLink();
};

#endif //FILE_SYSTEM_PROJECT_SYMBOLICLINK_H
