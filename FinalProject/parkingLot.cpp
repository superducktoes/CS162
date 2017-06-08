#include "parkingLot.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char ParkingLot::playRoom() {
  userChoice = 0;

  cout << "You are in the parking lot. " << endl;
  cout << "What do you want to do? " << endl;
  cout << "1. Go inside to the main lobby. " << endl;
  cout << "2. Explore the parking lot. " << endl;
  cout << "3. Quit the game. " << endl;
  cin >> userChoice;
  if(userChoice == 1) {
    cout << "Heading inside to the main lobby. " << endl;
    return 'r';
  } else if(userChoice == 2) {
    return 'x';
  } else if(userChoice == 3) {
    return 'q';
  } else {
    cout << "enter a number between 1 and 2. " << endl;
  }
}
