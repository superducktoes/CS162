#include <iostream>
#include <locale>
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int checkNumber(string message) {
  
  int number;
  bool continueLoop = false;
  
  while(continueLoop == false) {
    cout << message;
    cin >> number;
    
    if(cin.good() && number > 0) {
      continueLoop = true;
    } else {
      // this still needs to be worked on
      cin.clear();
      cout << "Your input was not valid." << endl;
    }
  }
  
  return number;
}

bool checkCharacter(string message) {
  char input;
  bool randomStartStatus;
  cout << message;
  cin >> input;
  
  if(std::isalpha(input) && (input == 'y' || input == 'Y')) {
    randomStartStatus = true;
  } else if(std::isalpha(input) && (input == 'n' || input == 'N')) {
    randomStartStatus = false;
  } else {
    randomStartStatus = false;
  }

  return randomStartStatus;
}
