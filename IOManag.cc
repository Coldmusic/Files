#include <iostream>
using namespace std;
#include <string>

#include "IOManag.h"

IOManag::IOManag()
{
}

IOManag::~IOManag() {}

void IOManag::intro()
{
  cout << endl;
  cout << "         --Welcome to File Manager--  "             << endl;
  cout << " **This program allows you to create new files**"   << endl;
  cout << "**read or write in existing files or delete them**" << endl;
  cout << endl;
}

void IOManag::main(int* choice)
{
  int c;
  cout << endl;
  cout << "  --Main Menu--  "          << endl;
  cout << "(1) Create new file"        << endl;
  cout << "(2) Read existing file"     << endl;
  cout << "(3) Write in existing file" << endl;
  cout << "(4) List all files"         << endl;
  cout << "(5) Remove file"            << endl;
  cout << "(0) Exit"                   << endl;
  cout << endl;

  while(*choice < 0 || *choice > 5) {
    cout << "Please enter your choice: ";
    cin >> c;
    *choice = c; 
  }
}

string IOManag::getName()
{
  string name = "default.txt";
  cout << "Please enter name of the file: ";
  cin >> name;
  if(cin.good()) return name;
}
