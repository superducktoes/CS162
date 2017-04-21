/******************************************************************
 *
 * Author: Nick Roy
 * Date: 4/6/2017
 * Description: Menu class. functions take a string to display and
 * then validates input.
 *
 * modified on 4/23/2017
 *
 * Sources:
 * - cin.good/cin.fail: http://stackoverflow.com/questions/13440831/how-do-i-check-if-input-is-an-integer-string
 *
 *****************************************************************/

#include <iostream>
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

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

char checkCharacter(string message, char letOne, char letTwo) {
  char input, returnChar;
  bool continueLoop = true;
  char letterOne = std::tolower(letOne);
  char letterTwo = std::tolower(letTwo);

  while(continueLoop == true) {
    cout << message;
    cin >> input;
    returnChar = std::tolower(input);
    if(input == letterOne || input == letterTwo) {
      continueLoop = false;
    }
  }

  return returnChar;
}

char menuPlayOn() {
  char c = checkCharacter("The game has ended. Do you want to play again? ( Y or N )", 'Y','N');

  return c;
}

void blankEnter() {
  char c;
  cin.clear();
  cin.clear();
  cout << "\nPress ENTER to continue" << endl;
  cin.ignore();
}
