#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include "Menu.h"

Menu::Menu() : choice(-1){}


Menu::~Menu() {}


void Menu::mainMenu()
{

  while(choice != 0) {
    choice = -1;
    manag.intro();
    manag.main(&choice);

    switch(choice) {
      case 1: {
        name = manag.getName();
        files.add(name);    
      } break;
      case 2: {
        name = manag.getName();
        files.read(name);  
      } break;
      case 3: {
        name = manag.getName();
        files.write(name);
      } break;
      case 4: {
        files.print();
      } break;
      case 5: {
        name = manag.getName();
        files.remove(name);
      } break;
      default: break;
    }
  }

}
