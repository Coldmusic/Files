#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include "Files.h"
#include "InFile.h"
#include <sys/stat.h>
#include <cstdio>
#include <unistd.h>

Files::Files() {
  files = new LinkedList<string>;
  num = 0;
}

Files::~Files()
{

}

void Files::add(string name)
{
  if(files->find(name)) return;
  n1 = name.c_str();
  OutFile file(n1);  
  files->pushBack(name); 
}

bool Files::check(string name)
{
  bool st = false;
  st = files->find(name);
  n1 = name.c_str();
  struct stat buffer;
  st = (stat (n1, &buffer) == 0);
  return st;
}

void Files::remove(string name)
{
  int st = 0;
  n1 = name.c_str();
  st = unlink(n1);
  if(st == 0) files->remove(name);
}

void Files::print()
{
  cout << "**Files**: " << endl;
  files->print();
}

void Files::read(string name)
{
  if(!(files->find(name))) return;

  n1 = name.c_str();
  InFile file(n1);

  file.read();
}

void Files::write(string name)
{
  if(!(files->find(name))) return;

  n1 = name.c_str();
  OutFile file(n1);
  file.write();
}
