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
  int antPosX = 5, antPosY = 1;
  bool userSetStart;
  
  
  cout << "This is a simulation of Langston's Ant" << endl;
  cout << "Let's get started with the simulation" << endl;

  rows = checkNumber("How many rows do you want the board to be? ");
  columns = checkNumber("How many columns do you want the board to be? ");

  antSteps = checkNumber("How many steps should the ant take? ");

  // checks to see whether the user entered y or n and returns a true or false
  userSetStart = checkCharacter("Would you like to set the position of the ant? (y/n) ");

  if(userSetStart) {
    antPosX = checkNumber("Enter the row to start off in: ");
    antPosY = checkNumber("Enter the column to start off in: ");
    // subtract 1 for the count by 0 offset
    antPosX--;
    antPosY--;
  } else {
    // need to generate a random number here for the x and y positions
    cout << "Looks like I'll be picking the starting point for the ant!";
  }
  
  // dynamically creates the array for the board
  // needs to be de-allocated later still
  boardArray = newBoard(rows,columns);
  Ant gameAnt(boardArray,antPosX,antPosY); // maybe the next game I can call him atom ant!
  cout << "This is what we're starting with: " << endl;
  showBoard(boardArray,rows,columns);
  cout << "Now lets let the little guy loose!" << endl;

  for(int i = 0; i < antSteps; i++) {
    std::system("clear");
    cout << "Currently on step " << (i+1) << " of " << antSteps << endl;
  }
  
  return 0;
}
