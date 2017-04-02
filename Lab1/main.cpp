/********************************************************************
 * Author: Nick Roy
 * Date: 4/2/2017
 * Description: Main class. Initializes the array based on user input
 * and then calls the readMatrix function to populate the array
 * and then the determinant function to solve.
 *
 ********************************************************************/

#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"
using namespace std;

int main() {

  int sizeOfMatrix = 0; 
  int *myMatrix;
  int original;
  bool keepGoing = false;
    
  cout << "Determinant calculator. Enter either 2 or 3 to create a 2x2 or 3x3 matrix. ";

  // does some input validation if the user did not enter two or three.
  if(sizeOfMatrix != 2 || sizeOfMatrix != 3) {
    while(!keepGoing) {
      cout << "\nEnter either 2 or 3: ";
      cin >> sizeOfMatrix;
      if(sizeOfMatrix == 2 || sizeOfMatrix == 3) {
	keepGoing = true;
      }
    }
  }

  // this is used later on to determine when we need a new row when showing the matrix
  original = sizeOfMatrix;
  // multiply by iteself so we can make a square
  sizeOfMatrix = sizeOfMatrix * sizeOfMatrix;
  
  // allocates the array based on the size provided by the user
  myMatrix = new int[sizeOfMatrix];

  // calls to the readMatrix function to get our input
  readMatrix(myMatrix, sizeOfMatrix);

  int answer = determinant(myMatrix,sizeOfMatrix);

  // output the answer and the matrix that was created
  cout << "The answer is: " << answer << endl;
  cout << "The final matrix created is: " << endl;
  for(int i = 0; i < sizeOfMatrix; i++) {
    
    cout << myMatrix[i] << " ";
    if((i+1)%original == 0) {
      cout << endl;
    }
  }
  
  // now that we're done with our array we need to de-allocate the memory.
  delete [] myMatrix;
  myMatrix = 0;
  
  return 0;
}
