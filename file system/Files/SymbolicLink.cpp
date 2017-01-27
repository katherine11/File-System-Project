#include "SymbolicLink.h"



SymbolicLink::SymbolicLink()
{

}
SymbolicLink::SymbolicLink(std::string name, Directory *directory) : File(name) {
    this->dir = directory;
}

SymbolicLink::SymbolicLink(std::string name, long size, Directory *directory) : File(name) {
    this->size = size;
    this->dir = directory;
}

SymbolicLink::SymbolicLink(const SymbolicLink &link) : File(link) {
    copy(link);
}

SymbolicLink &SymbolicLink::operator=(const SymbolicLink &link) {
    if(this != &link)
    {
        destroy();
        copy(link);
    }
    return *this;
}

SymbolicLink::~SymbolicLink() {
    destroy();
}

bool SymbolicLink::isRegularFile()
{
    return false;
}

bool SymbolicLink::isDirectory()
{
    return false;
}

bool SymbolicLink::isSymbolicLink()
{
    return true;
}

void SymbolicLink::destroy() {
    delete this->dir;
}

void SymbolicLink::copy(const SymbolicLink &link) {
    this->dir = link.dir;
}
