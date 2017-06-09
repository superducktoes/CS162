#include "parkingLot.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char ParkingLot::playRoom() {
  userChoice = 0;

  cout << "\nYou are in the parking lot. " << endl;
  cout << "What do you want to do? " << endl;
  cout << "1. Explore the parking lot. " << endl;
  cout << "2. Go inside to the main lobby. " << endl;
  cout << "0. Quit the game. " << endl;
  cin >> userChoice;
  
  if(userChoice == 2) {
    cout << "\nHeading inside to the main lobby. " << endl;
    return 'r';
  } else if(userChoice == 1) {
    return 'x';
  } else if(userChoice == 0) {
    return 'q';
  } else {
    cout << "\nPlease enter a number between 0 and 2.... " << endl;
  }
}
