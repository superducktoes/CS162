#include "mainLobby.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char MainLobby::playRoom() {
  userChoice = 0;
  
  cout << "you're in the main room now. " << endl;
  cout << "what do you want to do in here? " << endl;
  cout << "1. Go out to the parking lot. " << endl;
  cout << "2. Look around the lobby. " << endl;
  cout << "3. Quit the game. " << endl;
  cin >> userChoice;

  if(userChoice == 1) { 
    return 'l';
  } else if(userChoice == 2) {
    cout << "this is a nice lobby. " << endl;
  } else if(userChoice == 3) {
    return 'q';
  } else { 
    cout << "make sure to enter something else. " << endl;
  }
}
