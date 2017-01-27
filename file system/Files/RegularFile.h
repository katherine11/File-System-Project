#ifndef FILE_SYSTEM_PROJECT_REGULARFILE_H
#define FILE_SYSTEM_PROJECT_REGULARFILE_H

#include <ostream>
#include "File.h"
class RegularFile : public File{

private:
    std::string content;
    std::string extension;
    void copy(const RegularFile & regularFile);
public:

    RegularFile();
    RegularFile(std::string name);
    RegularFile(std::string name, long size, std::string content, std::string extension);
    RegularFile(const RegularFile &regularFile);
    RegularFile &operator=(const RegularFile & regularFile);
    virtual ~RegularFile();

    virtual bool isRegularFile();
    virtual bool isDirectory();
    virtual bool isSymbolicLink();

    friend std::ostream &operator<<(std::ostream &os, const RegularFile &file);

    const std::string getContent() const;

    void contcatenate(std::string content);
};


#endif //FILE_SYSTEM_PROJECT_REGULARFILE_H
