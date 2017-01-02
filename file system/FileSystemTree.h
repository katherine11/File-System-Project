#pragma once
#include "Directory.h"
#include <list>

class FileSystemTree;

struct Node
{
	Directory *previous;
	Directory *current;
	std::list<FileSystemTree> subTrees;
};

class FileSystemTree
{
private:
	Node *root;
	bool isRoot(const FileSystemTree &tree);
	bool isLeaf(const FileSystemTree &tree);
public:
	FileSystemTree();
	FileSystemTree(Node* const root);

	std::list<File> getTreeData(const FileSystemTree &tree);
	bool existsDirectory(const Directory& directory);
	void getFileNames(const Directory& directory);
};
