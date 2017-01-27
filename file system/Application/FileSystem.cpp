#include "../Files/RegularFile.h"
#include <iostream>
#include <string>
#include "FileSystem.h"
#include "../Files/SymbolicLink.h"
#include <ctime>
#include <string.h>
#include <sstream>

const std::string PWD = "pwd";
const std::string LS = "ls";
const std::string CD = "cd";
const std::string TOUCH = "touch";
const std::string CAT = "cat";
const std::string CP = "cp";
const std::string RM = "rm";
const std::string MKDIR = "mkdir";
const std::string RMDIR = "rmdir";
const std::string LN = "ln";
const std::string STAT = "stat";
const std::string DEFAULT_ROOT = "home/katerina";

FileSystem::FileSystem()
{
    this->tree = new FileSystemTree();
    this->prompt = Prompt();
    this->currentDirectoryTree = this->tree;
    this->rootDir = this->tree->getRoot()->current->getName();
}

void FileSystem::printCommandPrompt()
{
    std::cout << prompt;
}

void FileSystem::startApplication()
{
    while (true) {
        bool validCommand = false;
        printCommandPrompt();
        std::string inputCommand;
        std::getline(std::cin, inputCommand);

        if (inputCommand == PWD) {
             validCommand = true;
            pwd();
        }

        if (inputCommand.substr(0, LS.size()) == LS) {
            validCommand = true;
            ls(inputCommand.substr(LS.size()));
        }

        if (inputCommand.substr(0, CD.size()) == CD) {
            validCommand = true;
            cd(inputCommand.substr(CD.size()+1));
        }

        if (inputCommand.substr(0, TOUCH.size()) == TOUCH) {
            validCommand = true;
            touch(inputCommand.substr(TOUCH.size()));
        }

        if (inputCommand.substr(0, CAT.size()) == CAT) {
            validCommand = true;
            cat(inputCommand.substr(CAT.size()));
        }

        if (inputCommand.substr(0, CP.size()) == CP) {
            validCommand = true;
            cp(inputCommand.substr(CP.size()));
        }

        if (inputCommand.substr(0, RM.size()) == RM) {
            validCommand = true;
            rm(inputCommand.substr(RM.size()));
        }
        if (inputCommand.substr(0, RMDIR.size()) == RMDIR) {
            validCommand = true;
            rmDir(inputCommand.substr(RMDIR.size()+1));
        }

        if (inputCommand.substr(0, MKDIR.size()) == MKDIR) {
            validCommand = true;
            mkDir(inputCommand.substr(MKDIR.size()+1));
        }

        if (inputCommand.substr(0, LN.size()) == LN) {
            validCommand = true;
            ln(inputCommand.substr(LN.size()+1));

        }

        if (inputCommand.substr(0, STAT.size()) == STAT) {
            validCommand = true;
            stat(inputCommand.substr(STAT.size()));
        }

        if(!validCommand)
        {
            std::cout << "Command not found!" << std::endl;
        }
    }
}

void FileSystem::pwd()
{
    std::cout << rootDir;
    prompt.printWorkingDirectory();
    std::cout << std::endl;
}

void FileSystem::cd(std::string inputString) {

    if(inputString == "")
    {
        prompt.cleanWorkingDirectory();
        return;
    }

    if(inputString == ".")
    {
        return;
    }

    if(inputString == "..")
    {
        if(this->currentDirectoryTree->getRoot()->previous == NULL)
        {
            std::cout << "This is the root directory!"<< std::endl;
        } else {

            Node *newRoot = this->currentDirectoryTree->getRoot()->previous;

            FileSystemTree* tree = new FileSystemTree(newRoot);
            this->currentDirectoryTree = tree;
            this->prompt.deleteLastDirectory();

        }
        return;
    }

    char* dirs = strdup(inputString.c_str());
    char *dir;

    while((dir = strsep(&dirs, "/")))
    {
        Directory *directory = new Directory(dir);

        size_t size = this->currentDirectoryTree->getRoot()->current->getFilesInCurrentDirectory().getSize();
        for (int index = 0; index < size; ++index) {

            File *file = this->currentDirectoryTree->getRoot()->current->getFilesInCurrentDirectory().getAt(index);
            if(!existsFile(this->currentDirectoryTree,directory)) {
                std::cout << "No such directory!";
            }

            if(file->isDirectory()){
                if(*directory == *file){
                    Node *newRoot = new Node;
                    newRoot->current = directory;
                    newRoot->previous = this->currentDirectoryTree->getRoot();

                    FileSystemTree *newTree = new FileSystemTree(newRoot);
                    this->currentDirectoryTree = newTree;
                    this->prompt.addDirectory(dir);
                }
            }
        }
    }
}

void FileSystem::ls(std::string inputString) {

    if(inputString == "") {
        size_t size = this->currentDirectoryTree->getRoot()->current->getFilesInCurrentDirectory().getSize();
        for (int index = 0; index < size; ++index) {
            std::cout << this->currentDirectoryTree->getRoot()->current->getFilesInCurrentDirectory().getAt(index)->getName() << " ";
        }
        std::cout << std::endl;
        return;
    }
}

void FileSystem::touch(std::string inputString) {

    std::istringstream istringstream(inputString);
    std::string nextDir;
    while(istringstream >> nextDir)
    {
        RegularFile *regularFile = new RegularFile(nextDir);
        if(!existsFile(this->currentDirectoryTree, regularFile))
        {
            this->currentDirectoryTree->getRoot()->current->addFile(regularFile);
        }
    }
}

void FileSystem::cat(std::string inputString) {
    if(inputString == "")
    {
        std::string string;
        while(true)
        {
            std::cin >> string;
            if(string == ".")
            {
                break;
            }
            std::cout << string << std::endl;
        }
        return;
    }

    std::istringstream istringstream(inputString);
    std::string nextDir;
    Vector<RegularFile*> files;
    RegularFile *outpulFile = NULL;
    while(istringstream >> nextDir)
    {
        if(nextDir == ">")
        {
            istringstream >> nextDir;
            outpulFile = new RegularFile(nextDir);
        }

        RegularFile* file = new RegularFile(nextDir);
        files.pushBack(file);
    }

    if(outpulFile == NULL)
    {
        for (int index = 0; index < files.getSize(); ++index) {
            std::cout << files.getAt(index)->getContent() << std::endl;
        }

    }
    else
    {
        for (int index = 0; index < files.getSize(); ++index) {
            std::string content = files.getAt(index)->getContent();
            outpulFile->contcatenate(content);
        }
    }

}

void FileSystem::cp(std::string inputString) {

    std::istringstream istringstream(inputString);
    std::string nextDir;
    Vector<File*> files = this->currentDirectoryTree->getRoot()->current->getFilesInCurrentDirectory();
    Vector<File*> regularFiles;
    while(istringstream >> nextDir)
    {
        for (int index = 0; index < files.getSize(); ++index) {
            File *file = files.getAt(index);
            if(file->getName() == nextDir)
            {
                if(file->isRegularFile())
                {
                    regularFiles.pushBack(file);
                }

                if(file->isDirectory() && regularFiles.getSize() > 0)
                {
                    for (int index = 0; index < regularFiles.getSize(); ++index) {
                        Directory *directory = (Directory *&) file;
                        directory->getFilesInCurrentDirectory().pushBack(regularFiles.getAt(index));
                    }
                }
            }
        }
    }
}

void FileSystem::rm(std::string inputString) {

    Vector<File*> files = this->currentDirectoryTree->getRoot()->current->getFilesInCurrentDirectory();
    std::istringstream istringstream(inputString);
    std::string nextDir;
    while (istringstream >> nextDir) {

        for (int index = 0; index < files.getSize(); ++index) {

            File *file = files.getAt(index);

            if(file->isRegularFile())
            {
                this->currentDirectoryTree->getRoot()->current->deleteFile(file);
            }
        }
    }
}

void FileSystem::rmDir(std::string inputString) {

    std::istringstream istringstream(inputString);
    std::string nextDir;
    while (istringstream >> nextDir) {
        Directory *dirToRemove = new Directory(nextDir);
        if(!existsFile(this->currentDirectoryTree, dirToRemove))
        {
            std::cout << "No such directory!" << std::endl;
            return;
        }
        else
        {
        Node *nodeToRemove = new Node;

            size_t size = this->currentDirectoryTree->getRoot()->subTrees.getSize();

            for (int index = 0; index < size; ++index) {
                FileSystemTree* currentTree = this->currentDirectoryTree->getRoot()->subTrees.getAt(index);

                if(*currentTree->getRoot()->current == *dirToRemove){
                    nodeToRemove = currentTree->getRoot();
                    FileSystemTree *treeToRemove = new FileSystemTree(nodeToRemove);
                    this->currentDirectoryTree->deleteChild(treeToRemove);
                    this->currentDirectoryTree->getRoot()->current->deleteFile(dirToRemove);
                    this->prompt.deleteLastDirectory();
                }
            }
        }
    }
}

void FileSystem::mkDir(std::string inputString) {

    std::istringstream istringstream(inputString);
    std::string nextDir;
    while (istringstream >> nextDir) {

        Node *newNode = new Node;
        Directory *directory = new Directory(nextDir);
        newNode->current = directory;
        newNode->previous = this->currentDirectoryTree->getRoot();

        if(!existsFile(this->currentDirectoryTree, directory))
        {
            this->currentDirectoryTree->addChild(newNode);
            this->currentDirectoryTree->getRoot()->current->addFile(directory);
        }
        else
        {
            std::cout << "Such a directory already exists! " << std::endl;
        }
    }
}

void FileSystem::ln(std::string inputString) {

    std::istringstream istringstream(inputString);
    std::string nextDir;
    istringstream >> nextDir;
    if(nextDir == "-s")
    {
        while (istringstream >> nextDir) {
            std::string name = "link to " + nextDir;
            Directory* directory = new Directory(name);
            if(existsFile(this->currentDirectoryTree, directory))
            {
                SymbolicLink* link = new SymbolicLink(name, directory);

                if(!existsFile(this->currentDirectoryTree, directory))
                {
                    this->currentDirectoryTree->getRoot()->current->addFile(link);
                }
            }
        }
    }
}

void FileSystem::stat(std::string inputString) {

    std::istringstream istringstream(inputString);
    std::string nextDir;
    while (istringstream >> nextDir) {

        for (int index = 0; index < this->currentDirectoryTree->getRoot()->subTrees.getSize(); ++index) {
            Directory *current = this->currentDirectoryTree->getRoot()->subTrees.getAt(index)->getRoot()->current;
            if(current->getName() == nextDir)
            {
                std::cout << *current;
            }
        }
    }
}
