/*******************************************************************************
 *
 * Author: Nick Roy
 * Date: 5/7/2017
 * Description: Lab 5 that reverses a string, calculates a triangular number,
 * and the sum of the int's in an array.
 *
 *****************************************************************************/

#include <iostream>
#include <string>

#include "labFunctions.hpp"
#include "menu.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main() {

  int userChoice = 0;

  do {
    cout << "Enter a number to select one of the following: " << endl;
    cout << "\t1. Reverse a string. " << endl;
    cout << "\t2. Calculate the sum of an array. " << endl;
    cout << "\t3. Calculate the triangular number for an int. " << endl;
    userChoice = checkNumber("\t4. Quit the program. \n");

    cin.clear();
    cin.ignore();

    if(userChoice == 1) {
      string userInput = "";
      cout << "Enter a sentence: ";
      getline(cin,userInput);
      reverseString(userInput);
      cout << "\n\n";

    } else if(userChoice == 2) {
      int totalArrayEntries;
      int *myMatrix;

      totalArrayEntries = checkNumber("How many numbers do you want to add to the array? ");

      myMatrix = new int[totalArrayEntries];

      for(int i = 0; i < totalArrayEntries; i++) {
        cout << "Enter the number for position " << (i+1) << ": ";
        cin >> myMatrix[i];
      }

      int sumOfArray = sumArray(myMatrix,totalArrayEntries);
      cout << "\n\nThe total value of the array is " << sumOfArray << "\n\n";

      //free the memory
      delete [] myMatrix;
      myMatrix = 0;

    } else if(userChoice == 3) {
      int userNumber = 0;
      int triNumber = 0;
      userNumber = checkNumber("Enter a number to calculate the triangular number ");
      triNumber = triangularNumber(userNumber);
      cout << "\n\nThe triangular number of " << userNumber << " is " << triNumber << "\n\n";
    } else if(userChoice == 4) {
      userChoice = 4;
    } else {
      cout << "\n\nPlease enter a number between 1 and 4\n\n";
    }

  } while(userChoice != 4);
  return 0;
}
