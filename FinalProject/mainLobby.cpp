#include "mainLobby.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char MainLobby::playRoom() {
  userChoice = 0;

  cout << "You're in the main entrance of the building now. There's a few couches and some plants in here. " << endl;
  cout << "What do you want to do in here? " << endl;
  cout << "1. Go out to the parking lot. " << endl;
  cout << "2. Look around the lobby. " << endl;
  cout << "3. Enter the building and go into the main lobby. " << endl;
  cout << "0. Quit the game. " << endl;
  cin >> userChoice;

  if(userChoice == 1) {
    return 'l';
  } else if(userChoice == 2) {
    cout << "This is a nice lobby. The entrance to the office is at the other end of the room. " << endl;
  } else if(userChoice == 0) {
    return 'q';
  } else if(userChoice == 3) {
    return 'r';
  } else {
    cout << "I know you still haven't found your coffee but please make sure to enter a correct number..." << endl;
  }
}
