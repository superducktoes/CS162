#include <iostream>
#include "ant.hpp"

using std::cout;
using std::endl;

void Ant::setBoard(int** b) {
  board = b;
}

int** Ant::getBoard() {
  return board;
}

void Ant::setXPosition(int x) {
  posY = x;
}

void Ant::setYPosition(int y) {
  posX = y;
}

int Ant::getXPosition() {
  return posY;
}

int Ant::getYPosition() {
  return posX;
}

void Ant::setMaxXPosition(int mX) {
  maxX = mX;
}

void Ant::setMaxYPosition(int mY) {
  maxY = mY;
}

int Ant::getMaxXPosition() {
  return maxX;
}

int Ant::getMaxYPosition() {
  return maxY;
}

void Ant::setAntMoves(int m) {
  antMoves = m;
}

int Ant::getAntMoves() {
  return antMoves;
}

void Ant::setTileColor(int c) {
  antTileColor = c;
}

int Ant::getTileColor() {
  return antTileColor;
}


// this is the main part of the ant's movement. we need to find out first
// what colored square the ant is on and then move accordingly.
// 0's are white squares, 1's are black squares.
void Ant::moveAnt() {
  // we need to find out what color square the ant is on to determine his move
  int currentColor = getTileColor();
  
  if(currentColor == 0) {
    //if it's a white square we need to move right
    moveAntRight();
  } else if(currentColor == 2) {
    //if it's a black square we need to move left
    moveAntLeft();
  }
  
}
// what does this do?
// swaps the colors
// increments/decrements the ants position based on the way it is facing
// check to see if we are at the limit of the board and if the ant is swap it to the other side
// after incrementing we get the color of the tile moved to
//     - this needs to be done here becase once we move the ant it gets set
//     - to 1 and then the loop breaks.
// change the way the ant is facing
// sets the ant on the new tile.
void Ant::moveAntRight() {
  int currentTile = 0;
  switch(directionFacing) {
  case 'U':
    swapColors();
    posX++;
    collisionChecker();
    currentTile = board[posY][posX];
    setTileColor(currentTile);
    setAntFacing('R');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'D':
    swapColors();
    posX--;
    collisionChecker();
    currentTile = board[posY][posX];
    setTileColor(currentTile);
    setAntFacing('L');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'L':
    swapColors();
    posY--;
    collisionChecker();
    currentTile = board[posY][posX];
    setTileColor(currentTile);
    setAntFacing('U');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'R':
    swapColors();
    posY++;
    collisionChecker();
    currentTile = board[posY][posX];
    setTileColor(currentTile);
    setAntFacing('D');
    board[getXPosition()][getYPosition()] = 1;
    break;
  default:
    cout << "something went wrong." << endl; // theres really no reason to hit this.

 }
}

void Ant::moveAntLeft() {
  int currentTile = 0;
  switch(directionFacing) {
  case 'U':
    swapColors();
    posX--;
    collisionChecker();
    currentTile = board[posY][posX];
    setTileColor(currentTile);
    setAntFacing('L');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'D':
    swapColors();
    posX++;
    collisionChecker();
    currentTile = board[posY][posX];
    setTileColor(currentTile);
    setAntFacing('R');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'L':
    swapColors();
    posY++;
    collisionChecker();
    currentTile = board[posY][posX];
    setTileColor(currentTile);
    setAntFacing('D');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'R':
    swapColors();
    posY--;
    collisionChecker();
    currentTile = board[posY][posX];
    setTileColor(currentTile);
    setAntFacing('U');
    board[getXPosition()][getYPosition()] = 1;
    break;
  default:
    cout << "something went wrong." << endl; // theres really no reason to hit this.

 }
}

// sets the direction that the ant is facing. Will be a char that is either
// U, D, L, R
void Ant::setAntFacing(char s) {
  directionFacing = s;
}
char Ant::getAntFacing() {
  return directionFacing;
}

void Ant::swapColors() {

  int antX = getXPosition();
  int antY = getYPosition();
  int color = getTileColor();
    
  if(color == 0) {
    board[posY][posX] = 2;
  } else {
    board[posY][posX] = 0;
  }
}

void Ant::collisionChecker() {
  if(posX >= maxY) {
    posX = 0;
  }
  if(posX < 0) {
    posX = (maxY - 1);
  }
  if(posY < 0) {
    posY = (maxX - 1);
  }
  if(posY >= maxX) {
    posY = 0;
  }
}
