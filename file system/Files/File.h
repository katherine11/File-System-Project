
#ifndef FILE_SYSTEM_PROJECT_FILE_H
#define FILE_SYSTEM_PROJECT_FILE_H

#include <cstdio>
#include <iostream>
#include <string>

class File {
private:
    static size_t id_counter;
protected:
    const size_t file_id;
    std::string name;
    long size;
    char *lastAccessTime;
    char *lastContentChangeTime;
    char *lastMetaDataChangeTime;
    virtual void copy(const File &file);
    virtual void destroy();
public:
    File();
    File(std::string name);
    File(std::string name, long size);
    File(const File &file);
    File & operator= (const File & file);
    virtual ~File();

    virtual bool isRegularFile() = 0;
    virtual bool isDirectory() = 0;
    virtual bool isSymbolicLink() = 0;

    virtual const void serialize(std::ostream &os)const;
    virtual bool compare(const File &file);
    friend std::ostream &operator<<(std::ostream &os, const File &file);
    friend bool operator==(File &file1, const File &file2);
    friend bool operator!=(File &file1, const File &file2);

    std::string getName();
};

#endif //FILE_SYSTEM_PROJECT_FILE_H
