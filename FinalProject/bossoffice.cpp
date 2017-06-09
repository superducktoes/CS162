#include "bossoffice.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char BossOffice::playRoom() {
  userChoice = 0;
  cout << "\nWalking by the boss's office. Definitely need to stay quiet. " << endl;
  cout << "1. Sneak into the boss's office and check it out. " << endl;
  cout << "2. Sneak by the office and into the break room. " << endl;
  cout << "3. Head back to that dark hallway. " << endl;
  cout << "0. Quit the game. " << endl;
  cin >> userChoice;

  if(userChoice == 1) {
    return 'x';
  } else if(userChoice == 2) {
    return 'l';
  } else if(userChoice == 3) {
    return 'r';
  } else if(userChoice == 0) {
    return 'q';
  } else {
    cout << "\nSince we're being sneaky I'll give you a hint. Need to pick something between 1 and 3. " << endl;
  }
}
