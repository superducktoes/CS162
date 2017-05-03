#include <iostream>
#include <string>

#include "labFunctions.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {

  string myString = "this is a testa";

  static int arraySize = 5;
  int testArray[arraySize] = {1,2,3,4,6};

  reverseString(myString);

  int sumOfArray = sumArray(testArray,arraySize);
  int triangle = triangularNumber(5);

  cout << triangle << endl;
  cout << sumOfArray << endl;

  return 0;
}
