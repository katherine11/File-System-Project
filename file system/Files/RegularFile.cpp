#include "RegularFile.h"

const std::string DEFAULT_EXTENSION = "txt";

RegularFile::RegularFile() : File(){
    this->content = "";
    this->extension = DEFAULT_EXTENSION;
}

RegularFile::RegularFile(std::string name) : File(name) {

}

RegularFile::RegularFile(std::string name, long size, std::string content, std::string extension) :
        File(name,size) {
    this->content = content;
    this->extension = extension;
}

RegularFile::RegularFile(const RegularFile &regularFile) : File(regularFile){
    copy(regularFile);
}

RegularFile &RegularFile::operator=(const RegularFile &regularFile) {
    if(this != &regularFile)
    {
        File::operator=(regularFile);
        copy(regularFile);
    }
    return *this;
}

RegularFile::~RegularFile() {

}

bool RegularFile::isRegularFile() {
    return true;
}

bool RegularFile::isDirectory() {
    return false;
}

bool RegularFile::isSymbolicLink() {
    return false;
}

void RegularFile::copy(const RegularFile &regularFile) {
    this->content = regularFile.content;
    this->extension = regularFile.extension;
}

std::ostream &operator<<(std::ostream &os, const RegularFile &file) {
    os << static_cast<const File &>(file) << "Content: \n" << file.content;
    return os;
}

const std::string RegularFile::getContent() const {
    return content;
}

void RegularFile::contcatenate(std::string content) {
    this->content += content;
}
