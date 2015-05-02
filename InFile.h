#ifndef INFILE_H
#define INFILE_H

#include "File.h"

class InFile : public File
{
  public:
    InFile(const char*);
    ~InFile();
    bool read();
  private:
    ifstream *file;

};
#endif
