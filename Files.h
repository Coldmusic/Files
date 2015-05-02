#ifndef FILES_H
#define FILES_H

#include "LinkedList.h"
#include "File.h"
#include "OutFile.h"

class Files
{
  public:
    Files();
    ~Files();
    void add(string);
    bool check(string);
    void remove(string);
    void write(string);
    void read(string);
    void print();
  private:
    LinkedList<string>* files;
    int num;
    const char* n1;
};
#endif
