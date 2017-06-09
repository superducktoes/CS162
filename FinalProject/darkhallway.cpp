#include "darkhallway.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

char DarkHallway::playRoom() {
  userChoice = 0;
  cout << "\nOh man this is a dark hallway. The one good thing is that it makes Monday morning easier.... " << endl;
  cout << "1. Do you want to search the floor for anything? " << endl;
  cout << "2. Or maybe head over to the bosses office? " << endl;
  cout << "3. We can also head back to the reception area if it's too scary in here. " << endl;
  cout << "0. Exit the game. " << endl;
  cin >> userChoice;

  if(userChoice == 1) {
    cout << "\nOnly dust and broken dreams on this floor. " << endl;
  } else if(userChoice == 2) {
    return 'l';
  } else if(userChoice == 3) {
    return 'u';
  } else if(userChoice == 0) {
    return 'q';
  } else {
    cout << "\nI know it was scary in that hall but let's pick a number between 0 and 3. " << endl;
  }
}
