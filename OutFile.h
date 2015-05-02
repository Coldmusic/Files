#ifndef OUTFILE_H
#define OUTFILE_H

#include <fstream>
#include <cstdlib>

#include "File.h"

class OutFile : public File
{
  public:
    OutFile(const char*);
    ~OutFile();
    bool write(string);
    bool write();
    virtual bool operator==(const char*);
  private:
    ofstream *file;

};
#endif
