/*********************************************************************
 *
 * Author: Nick Roy
 * Date: 6/4/2017
 * Description: Palindrome stack. Loops through the word entered by the
 * user and pushes on the stack. Second loop pops off the stack in
 * order to generate the palindrome.
 *
 ********************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include "stack.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void palindromeStack(string p) {
  string palindrome = p;
  std::stack<char> myPalStack;

  for(int i=0; i<palindrome.length(); i++) {
    myPalStack.push(palindrome.at(i));
  }

  cout << "The word you entered is: " << palindrome << endl;
  cout << "\nThe palindrome of the word is: ";

  while(!myPalStack.empty()) {
    cout << myPalStack.top();
    myPalStack.pop();
  }
  cout << endl;
}
