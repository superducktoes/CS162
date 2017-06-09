#include "reception.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char Reception::playRoom() {
  userChoice = 0;

  cout << "\nYou are now in the reception area. " << endl;
  cout << "Doesn't look like anyone is at the front desk yet. " << endl;
  cout << "What do you want to do in this room? " << endl;
  cout << "1. Look on the desk to see if there is anything interesting. " << endl;
  cout << "2. Go back to the main lobby. " << endl;
  cout << "3. Walk forward by the reception desk and head to your desk " << endl;
  cout << "4. Walk down the dark hallway in the opposite direction of your desk. " << endl;
  cout << "0. Quit playing the game. " << endl;
  cin >> userChoice;
  
  if(userChoice == 1){
    cout << "\nDon't look at other peoples things on their desk! Although that does look like a tasty lunch sitting there..." << endl;
  } else if(userChoice == 2) {
    cout << "\nHeading back to the main lobby. " << endl;
    return 'l';
  } else if(userChoice == 3) {
    cout << "\nLet me head to my desk. " << endl;
    return 'u';
  } else if(userChoice == 4) {
    cout << "\nThankfully the lights are dimmed. Should make my morning easier..." << endl;
    return 'd';
  } else if(userChoice == 0) {
    return 'q';
  } else {
    cout << "\nI know you still haven't found your coffee but please make sure to enter a correct number..." << endl;
  }

}
