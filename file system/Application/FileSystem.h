#ifndef FILE_SYSTEM_PROJECT_FILESYSTEM_H
#define FILE_SYSTEM_PROJECT_FILESYSTEM_H
#include "../Files/Directory.h"
#include <string>
#include "../Structures/FileSystemTree.h"
#include "../Structures/Prompt.h"

class FileSystem
{
private:
    std::string rootDir;
    Prompt prompt;
    FileSystemTree *tree;
    FileSystemTree *currentDirectoryTree;
    void printCommandPrompt();
public:

    FileSystem();

    void startApplication();

    void pwd();

    void cd(std::string basic_string);

    void ls(std::string inputString);

    void cat(std::string inputString);

    void cp(std::string inputString);

    void rm(std::string inputString);

    void rmDir(std::string inputString);

    void mkDir(std::string inputString);

    void ln(std::string inputString);

    void stat(std::string inputString);

    void touch(std::string inputString);
};

#endif //FILE_SYSTEM_PROJECT_FILESYSTEM_H
