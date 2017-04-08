/********************************************************
 * 
 * Author: Nick Roy
 * Date: 4/6/2017
 * Description: Main file for the langton's ant program
 *
 ********************************************************/

#include <iostream>
#include <cstdlib>
#include "board.hpp"
#include "menu.hpp"
#include "ant.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

  int **boardArray;
  int rows, columns; // used to get the size of the board to create
  int antSteps; // how many steps should our ant take?
  int antPosX = 0, antPosY = 0;
  bool userSetStart;
  
  cout << "This is a simulation of Langston's Ant" << endl;
  cout << "Let's get started with the simulation" << endl;

  rows = checkNumber("How many rows do you want on the board: ");
  columns = checkNumber("How many columns do you want on the board: ");
  antSteps = checkNumber("How many steps do you want the ant to take: ");

  // checks to see whether the user entered y or n and returns a true or false
  userSetStart = checkCharacter("Would you like to set the position of the ant? (y/n) ",'y','n');
  
  // gets the start position from the ant either from the user or
  // randomly generated if they want or if they don't enter y or n
  
  if(userSetStart) {
    cout << "Enter the starting row for the ant between 0 and " << (rows-1) << endl;
    antPosX = checkNumberRange("Starting row: ",0,(rows-1));
    cout << "Enter the starting column for the ant between 0 and " << (columns-1) << endl;
    antPosY = checkNumberRange("Starting column: ",0,(columns-1));
  } else {
    cout << "Looks like I'll be picking the starting point for the ant!";
    antPosX = generateRandom(rows);
    antPosY = generateRandom(columns);  
    cout << "\n\nStarting the ant at position: (" << antPosX << "," << antPosY << ")" << endl;
  }

  
  // dynamically creates the array for the board
  boardArray = newBoard(rows,columns);  
  // create our ant object
  Ant gameAnt(boardArray,antPosX,antPosY,rows,columns,antSteps);
  
  cout << "Now lets let the little guy loose!" << endl;
  cout << "Press enter to start!\n " << endl;
  
  blankEnter();
  
  for(int i = 0; i < antSteps; i++) {
    std::system("clear");
    gameAnt.moveAnt();
    showBoard(boardArray,rows,columns);
    cout << "\nCurrently on step " << (i+1) << " of " << antSteps << endl;
    if((i+1) ==  antSteps) {
      cout << "\n\nFinished! " << endl;
    } else {
      cout << "\n\nHold Enter to have the ant move" << endl;
    }
    blankEnter();
  }
  
  // free up our board constructed before exiting  
  delete [] boardArray;
  boardArray = 0;
  
  return 0;
}
