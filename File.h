#ifndef FILE_H
#define FILE_H

class File
{
  public:
    File(const char*);
    ~File();
    const char* getName();
    virtual bool operator==(const char*);
  protected:
    const char* filename;

};
#endif
