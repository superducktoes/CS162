/******************************************************************
 * 
 * Author: Nick Roy
 * Date: 4/2/2017
 * Description: Determinant function takes the array as a pointer
 * and the size of the array and calculates accordingly.
 *
 ******************************************************************/

#include <iostream>
#include "determinant.hpp"
using std::cout;

int determinant(int *myMatrix, int sizeOfMatrix) {

  int answer = 0;
  // use 4 and 9 since we doubled them earlier to get a square
  
  if(sizeOfMatrix == 4) {
    answer = ((myMatrix[0]*myMatrix[3]) - (myMatrix[1]*myMatrix[2]));
  } else if(sizeOfMatrix == 9)  {
    // https://en.wikipedia.org/wiki/Determinant#3_.C3.97_3_matrices
    answer = myMatrix[0]*(myMatrix[4]*myMatrix[8]-myMatrix[5]*myMatrix[7]) -
      myMatrix[1]*(myMatrix[3]*myMatrix[8]-myMatrix[5]*myMatrix[6]) +
      myMatrix[2]*(myMatrix[3]*myMatrix[7]-myMatrix[4]*myMatrix[6]);
  } else {
    cout << "Problem determining the size of your matrix. Returning 0";
  }

  return answer;

}
