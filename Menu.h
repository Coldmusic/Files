#ifndef MENU_H
#define MENU_H

#include "IOManag.h"
#include "Files.h"

class Menu
{
  public:
    Menu();
    ~Menu();
    void mainMenu();
  private:
    Files files;
    IOManag manag;
    int choice;
    string name;
    const char* name1;
};
#endif
