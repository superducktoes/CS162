/**********************************************************************
 *
 * Author: Nick Roy
 * Date: 4/6/2017
 * Description: Board class. Creates a new board dynamically and then
 * handles displaying the board with the values
 *
 **********************************************************************/

#include <iostream>
#include "board.hpp"
using std::cin;
using std::cout;
using std:: endl;
using std::string;

int** newBoard(int rows, int columns) {
  // create a new pointer to an array
  int** newBoardArray = new int*[rows];
  // create the pointers to the columns
  for(int i = 0; i < rows; i++) {
    newBoardArray[i] = new int[columns];
  }

  // populate the new array with 0's.
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      newBoardArray[i][j] = 0;
    }
  }

  return newBoardArray;
}

// 1 is the ant, 0 is a white square, 2 is a black square
void showBoard(int** gameBoard, int rows, int columns) {

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      
      if(gameBoard[i][j] == 1) {
	cout << "8";
      } else if(gameBoard[i][j] == 0) {
	cout << " ";
      } else if(gameBoard[i][j] == 2) {
	cout << "#";
      }

    }
    cout << endl;
  }
  
}
