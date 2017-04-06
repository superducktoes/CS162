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

void showBoard(int** gameBoard, int rows, int columns) {

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      
      if(gameBoard[i][j] == 1) {
	cout << " @ ";
      }else if(gameBoard[i][j] == 0) {
	cout << "   "; //CHANGE THIS BEFORE SUBMITTING!!
      } else if(gameBoard[i][j] == 2) {
	cout << " # ";
      }

    }
    cout << endl;
  }
  
}
