#include <iostream>
using namespace std;
#include <string>

#include "OutFile.h"
#include <cstdlib>
#include <fstream>

OutFile::OutFile(const char* name) : File(name)
{
  file = new ofstream(filename, ios::out);
  if(!*file)
    cout << "Could not open file" << endl;
}

OutFile::~OutFile()
{
  delete file;
}

bool OutFile::write(string text)
{
  if(!*file) return false;
 
  *file << text << endl;
  return true;
}

bool OutFile::write()
{
  string text;
  if(!*file) return false;

  while(cin >> text && text != "exit") 
    *file << text << endl;

  cout << "Done!" << endl;
  return true;

}

bool OutFile::operator==(const char* n)
{
  if(filename == n) return true;
  else return false;
}
