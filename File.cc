#include <iostream>
using namespace std;
#include <string>

#include "File.h"

File::File(const char* name) : filename(name) {}

File::~File() {}

const char* File::getName()
{
  return filename;
}

bool File::operator==(const char* name)
{
  if(name == filename) return true;
  else return false;
}
