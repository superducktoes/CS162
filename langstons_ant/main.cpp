#include <iostream>
#include <cstdlib>
#include <time.h>
#include "board.hpp"
#include "menu.hpp"
#include "ant.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int generateRandom(int max) {

  int randomNum;
  srand(time(NULL));
  randomNum = rand() % max + 1;

  return randomNum;
}
  

int main() {

  int **boardArray;
  int rows, columns; // used to get the size of the board to create
  int antSteps; // how many steps should our ant take?
  int antPosX = 5, antPosY = 1;
  bool userSetStart;
  char ch;
  
  cout << "This is a simulation of Langston's Ant" << endl;
  cout << "Let's get started with the simulation" << endl;

  rows = checkNumber("How many rows do you want the board to be? ");
  columns = checkNumber("How many columns do you want the board to be? ");

  antSteps = checkNumber("How many steps should the ant take? ");

  // checks to see whether the user entered y or n and returns a true or false
  userSetStart = checkCharacter("Would you like to set the position of the ant? (y/n) ");
  
  // gets the start position from the ant either from the user or
  // randomly generated
  if(userSetStart) {
    antPosX = checkNumber("Enter the row to start off in: ");
    antPosY = checkNumber("Enter the column to start off in: ");
  } else {
    cout << "Looks like I'll be picking the starting point for the ant!";
    antPosX = generateRandom(rows);
    antPosY = generateRandom(columns);  
  }
  
  // subtract 1 for the count by 0 offset
  //antPosX = antPosX - 1;
  //antPosY = antPosY - 1;

  // dynamically creates the array for the board
  // needs to be de-allocated later still
  boardArray = newBoard(rows,columns);
  Ant gameAnt(boardArray,antPosX,antPosY,rows,columns,antSteps); // create our ant object
  cout << "This is the board that  we're starting with: " << endl;
  showBoard(boardArray,rows,columns);
  // this needs to display as +1 because of counting by 0
  cout << "Starting at position: " << (gameAnt.getXPosition() + 1) << " " << (gameAnt.getYPosition() + 1) << endl;
  cout << "Now lets let the little guy loose!" << endl;
  cout << "color for the ant is: " << gameAnt.getTileColor();
  cout << "Press enter to start! " << endl;

  cin.clear();
  cin.ignore();
  cin.get(ch);

  for(int i = 0; i < antSteps; i++) {
    std::system("clear");
    cout << "Currently on step " << (i+1) << " of " << antSteps << endl;
    gameAnt.moveAnt();
    showBoard(boardArray,rows,columns);
    cin.clear();
    cin.ignore();
    cin.get(ch);
  }

  showBoard(boardArray,rows,columns);
  cout << "final spots: " << gameAnt.getXPosition() << "   " << gameAnt.getYPosition() << endl;
  return 0;
}
