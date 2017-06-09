#include "breakroom.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char BreakRoom::playRoom() {
  userChoice = 0;
  cout << "\nIn the break room. Couple people standing around waiting for coffee to brew. " << endl;
  cout << "1. Get some coffee. " << endl;
  cout << "2. Head back in the direction of the boss's office. " << endl;
  cout << "0. Quit the game. " << endl;
  cin >> userChoice;

  if(userChoice == 1) {
    return 'i';
  } else if(userChoice == 2) {
    return 'r';
  } else if(userChoice == 0) {
    return 'q';
  } else {
    cout << "\nI know we finally found the coffee make but lets not get too excited. You need to enter between 0 and 2. " << endl;
  }
  
}
