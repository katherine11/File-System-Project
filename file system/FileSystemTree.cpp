#include "FileSystemTree.h"


FileSystemTree::FileSystemTree()
{
	this->root = nullptr;
}

FileSystemTree::FileSystemTree(Node* const root)
{
	this->root = root;
}

std::list<File> FileSystemTree::getTreeData(const FileSystemTree &tree)
{
	std::list<File> result;
	while (!isLeaf(tree))
	{
		result.push_back(*tree.root->current);
	}
	return result;
}

bool FileSystemTree::isRoot(const FileSystemTree& tree)
{
	return tree.root->previous == nullptr;
}

bool FileSystemTree::isLeaf(const FileSystemTree& tree)
{
	return tree.root->subTrees.size() == 0;
}

bool FileSystemTree::existsDirectory(const Directory& directory)
{
	return false;	
}

void FileSystemTree::getFileNames(const Directory& directory)
{
	
}
