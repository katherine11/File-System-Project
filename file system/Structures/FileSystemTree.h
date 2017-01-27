#ifndef FILE_SYSTEM_PROJECT_FILESYSTEMTREE_H
#define FILE_SYSTEM_PROJECT_FILESYSTEMTREE_H

#include <ostream>
#include "../Files/Directory.h"
#include "Vector.hpp"

class FileSystemTree;

struct Node
{
    Node *previous;
    Directory *current;
    Vector<FileSystemTree*> subTrees;
};

class FileSystemTree
{
private:
    Node *root;
    bool isRoot(const FileSystemTree &tree);
    bool isLeaf(const FileSystemTree &tree);
    void copy(const FileSystemTree &tree);
    void destroy();
public:
    FileSystemTree();
    FileSystemTree(Node* const root);
    FileSystemTree(const FileSystemTree &tree);
    FileSystemTree &operator=(const FileSystemTree &tree);
    ~FileSystemTree();

    void addChild(Node *node);
    void deleteChild(FileSystemTree *tree);
    friend bool operator==(FileSystemTree &tree1, const FileSystemTree &tree2);
//    friend bool operator!=(const FileSystemTree &tree1, const FileSystemTree &tree2);

    friend std::ostream &operator<<(std::ostream &os, const FileSystemTree &tree);

    friend bool existsFile(FileSystemTree *tree, File* file);

    Node *getRoot() const;
};

#endif //FILE_SYSTEM_PROJECT_FILESYSTEMTREE_H
