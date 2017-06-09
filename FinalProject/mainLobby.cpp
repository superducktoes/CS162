#include "mainLobby.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char MainLobby::playRoom() {
  userChoice = 0;

  cout << "\nYou're in the main entrance of the building now. There's a few couches and some plants in here. " << endl;
  cout << "What do you want to do in here? " << endl;
  cout << "1. Look around the lobby. " << endl;
  cout << "2. Go out to the parking lot. " << endl;
  cout << "3. Enter the building and go into the reception area. " << endl;
  cout << "0. Quit the game. " << endl;
  cin >> userChoice;

  // re-arranged to keep consistent with how the menu is in othe rooms
  if(userChoice == 2) {
    return 'l';
  } else if(userChoice == 1) {
    cout << "\nThis is a nice lobby. The entrance to the office is at the other end of the room. " << endl;
  } else if(userChoice == 0) {
    return 'q';
  } else if(userChoice == 3) {
    return 'r';
  } else {
    cout << "\nI know you still haven't found your coffee but please make sure to enter a correct number..." << endl;
  }
}
