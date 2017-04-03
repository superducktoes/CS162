/*************************************************
 *
 * Author: Nick Roy
 * Date: 4/2/1017
 * Description: readMatrix function takes the array as a pointer
 * and the size of the array and populates the array/matrix with
 * user input
 *
 ************************************************/

#include <iostream>
#include "readMatrix.hpp"
using std::cout;
using std::cin;
using std::endl;

void readMatrix(int *myMatrix, int sizeOfMatrix) {

  cout << "Enter the values for the array: " << endl;
  for(int i = 0; i < sizeOfMatrix; i++) {
    cout << "Enter the value for " << (i + 1) << ": ";
    cin >> myMatrix[i];
  }

}
