#include <cstring>
#include "File.h"

size_t File::id_counter = 0;

File::File() : file_id(id_counter){
    id_counter++;
    this->size = 0;
    this->name = "";
    time_t now = time(0);
    this->lastAccessTime = ctime(&now);
    this->lastContentChangeTime = ctime(&now);
    this->lastMetaDataChangeTime = ctime(&now);
}

File::File(std::string name) : File() {
    this->name = name;
}

File::File(std::string name, long size) : File(name){
    this->size = size;
}

File::File(const File &file) : file_id(id_counter) {
    copy(file);
}

File &File::operator=(const File &file) {

    if(this != &file)
    {
        destroy();
        copy(file);
    }

    return *this;
}

File::~File() {
    destroy();
}

void File::copy(const File &file) {
    this->name = file.name;
    std::strcpy(lastAccessTime,file.lastAccessTime);
    std::strcpy(lastContentChangeTime,file.lastContentChangeTime);
    std::strcpy(lastMetaDataChangeTime,file.lastMetaDataChangeTime);
}

void File::destroy() {
    delete[] lastAccessTime;
    delete[] lastContentChangeTime;
    delete[] lastMetaDataChangeTime;
}

const void File::serialize(std::ostream &os)const{
    os << "i_node: " << file_id <<"\nname: " << name << "\nsize: " << size << "\nLast access time: "
       << lastAccessTime << "\nLast content modification time: " << lastContentChangeTime << "\nLast metadata modified time: "
       << lastMetaDataChangeTime;
}

std::ostream &operator<<(std::ostream &os, const File &file) {
    file.serialize(os);
    return os;
}

std::string File::getName() {
    return this->name;
}
bool File::isDirectory()
{
    return false;
}

bool File::isRegularFile()
{
    return false;
}

bool File::isSymbolicLink()
{
    return false;

}

bool File::compare(const File &file) {
    return this->file_id == file.file_id || this->name == file.name;
}

bool operator==(File &file1, const File &file2) {
    return file1.compare(file2);
}

bool operator!=(File &file1, const File &file2)
{
    return !(file1 == file2);
}

