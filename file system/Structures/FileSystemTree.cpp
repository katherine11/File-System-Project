#include <iostream>
#include "FileSystemTree.h"

FileSystemTree::FileSystemTree()
{
    this->root = new Node;
    this->root->current = new Directory();
    this->root->previous = NULL;
    Vector<FileSystemTree*> subTrees;
    this->root->subTrees = subTrees;
}

FileSystemTree::FileSystemTree(Node* const root)
{
    this->root = root;
}

FileSystemTree::FileSystemTree(const FileSystemTree &tree) {
    copy(tree);
}

FileSystemTree &FileSystemTree::operator=(const FileSystemTree &tree) {

    if(this != &tree)
    {
        destroy();
        copy(tree);
    }

    return *this;
}

FileSystemTree::~FileSystemTree() {
    destroy();
}

Node *FileSystemTree::getRoot() const {
    return root;
}

void FileSystemTree::copy(const FileSystemTree &tree) {

    this->root = tree.root;
}

void FileSystemTree::destroy() {
    delete this->root;
}

bool FileSystemTree::isRoot(const FileSystemTree& tree)
{
    return tree.root->previous == nullptr;
}

bool FileSystemTree::isLeaf(const FileSystemTree& tree)
{
    return tree.root->subTrees.getSize() == 0;
}

std::ostream &operator<<(std::ostream &os, const FileSystemTree &tree) {

    std::cout << "\nRoot: " <<tree.getRoot()->current->getName();

    Vector<FileSystemTree*> copy = tree.getRoot()->subTrees;
    for (int index = 0; index < copy.getSize() ; ++index) {
        std::cout << "\nSub-directories: " << copy.getAt(index)->getRoot()->current->getName() << " ";
    }
    std::cout << std::endl;
    return os;
}

bool operator==(FileSystemTree &tree1, const FileSystemTree &tree2) {
    Node *tree1Root = tree1.getRoot();
    Node *tree2Root = tree2.getRoot();
    return *tree1Root->current == *tree2Root->current;
}

bool existsFile(FileSystemTree *tree, File* file) {
    return tree->getRoot()->current->getFilesInCurrentDirectory().containsElement(file);
}

void FileSystemTree::addChild(Node *node) {

    this->root->subTrees.pushBack(new FileSystemTree(node));

}

void FileSystemTree::deleteChild(FileSystemTree* tree) {
    if(this->root->subTrees.containsElement(tree))
    {
        this->root->subTrees.deleteElement(tree);
    }
}

