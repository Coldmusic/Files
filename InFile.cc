#include <iostream>
using namespace std;
#include <string>

#include "InFile.h"
#include <fstream>
#include <cstdlib>

InFile::InFile(const char* name) : File(name)
{
  file = new ifstream(filename, ios::in);
  if(!*file) cout << "Could not open file" << endl;
}

InFile::~InFile()
{
  delete file;
}

bool InFile::read()
{
  string text;
  if(!*file) return false;
  
  while(*file >> text) {
    cout << text << endl;
  }

  return true;
}
