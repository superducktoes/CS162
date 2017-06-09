#include "yourdesk.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char YourDesk::playRoom() {
  userChoice = 0;
  cout << "You've made it to your desk. " << endl;
  cout << "What do you want to do here? " << endl;
  cout << "\n1. Try to start getting some work done. " << endl;
  cout << "2. Head back towards the reception area. " << endl;
  cout << "0. Quit the game. " << endl;
  cin >> userChoice;

  if(userChoice == 2) {
    cout << "\nLet's head back to the reception area. " << endl;
    return 'd';
  } else if(userChoice == 1) {
    return 'i';
  } else if(userChoice == 0) {
    return 'q';
  } else {
    cout << "\nI know you still haven't found your coffee but please make sure to enter a correct number..." << endl;
  }
}
