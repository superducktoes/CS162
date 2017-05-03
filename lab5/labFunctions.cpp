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

using std::cout;
using std::endl;
using std::string;

// adds up all of the elements of the array
// takes the array and the length of the array as an argument
int sumArray(int numberArray[], int arrayLength) {

  int position = arrayLength - 1;

  if(position >= 1) {
    return numberArray[position] + sumArray(numberArray,position);
  } else if(position == 0) {
    // really this covers if there is only one element in the array.
    return numberArray[position];
  } else {
    return 0;
  }
}

// calculates the triangular number of the array
// only needs one number and returns the answer
int triangularNumber(int n) {
  if(n >= 1) {
    return n + triangularNumber(n-1);
  } else {
    return 0;
  }
}


// takes a string and using recursion is subtracts 1 char per interation
void reverseString(string s) {

  int stringLength = s.length();

  if(stringLength == 1) {
    cout << s << "(newline)"<< endl;
  } else {
    cout << s[stringLength - 1];
    reverseString(s.erase(s.length()-1));
  }

}
