/******************************************************************
 *
 * Author: Nick Roy
 * Date: 4/6/2017
 * Description: Menu class. functions take a string to display and 
 * then validates input.
 *
 * Sources:
 * - cin.good/cin.fail: http://stackoverflow.com/questions/13440831/how-do-i-check-if-input-is-an-integer-string
 *
 *****************************************************************/

#include <iostream>
#include <locale>
#include <time.h>
#include <cstdlib>
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int generateRandom(int max) {

  int randomNum;
  srand(time(NULL));
  // -1 to take care of the array count by 0 offset or else it segfaults
  randomNum = rand() % (max-1) + 1;

  return randomNum;
}

//verifies whether or not the input is an integer and returns it
int checkNumber(string message) {
  
  int number;
  bool continueLoop = true;
  
  while(continueLoop == true) {
    cout << message;
    cin >> number;
    
    if(cin.good() && (number >= 0)) {
      continueLoop = false;
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
int checkNumberRange(string s, int low, int high) {
  int number;
  bool continueLoop = true;

  while(continueLoop == true) {
    cout << s;
    cin >> number;
    if(cin.good() && (number >= low && number <= high)) {
      continueLoop = false;
    } else if(cin.fail()) {
      cout << "Your input is not in the correct range." << endl;
      cout << "Enter a number between " << low << " and " << high << endl;

      cin.clear();
      cin.ignore();
    }
  }
  return number;
}

// verifies whether or not the input is a char and returns it
// also takes two inputs to see if they match

bool checkCharacter(string message, char letOne, char letTwo) {
  char input;
  bool randomStartStatus;
  char letterOne = std::tolower(letOne);
  char letterTwo = std::tolower(letTwo);
  cout << message;
  cin >> input;
  
  if(std::isalpha(input) && input == letterOne) {
    randomStartStatus = true;
  } else if(std::isalpha(input) || input == letterTwo) {
    randomStartStatus = false;
  } else {
    randomStartStatus = false;
  }

  return randomStartStatus;
}

void blankEnter() {

  cin.clear();
  cin.ignore();
  cin.ignore();
}
