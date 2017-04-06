#include <iostream>
#include <locale>
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//verifies whether or not the input is an integer and returns it
int checkNumber(string message) {
  
  int number;
  bool continueLoop = false;
  
  while(continueLoop == false) {
    cout << message;
    cin >> number;
    
    if(cin.good() && (number >= 0)) {
      continueLoop = true;
    } else if(cin.fail()) {
      // this still needs to be worked on
      cin.clear();
      cin.ignore();
      cout << "Your input was not valid." << endl;
    }
  }
  
  return number;
}

// takes two numbers and verifies that it is within the range and is an int.
int checkNumberRange(string s, int low, int high) { return low; }

// verifies whether or not the input is a char and returns it
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
