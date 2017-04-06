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
  posX = x;
}

void Ant::setYPosition(int y) {
  posY = y;
}

int Ant::getXPosition() {
  return posX;
}

int Ant::getYPosition() {
  return posY;
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
  cout << "the ant is currently on color: " << currentColor << endl;
  cout << "X: " << posX << "Y: " << posY << endl;
  
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
// after incrementing we get the color of the tile moved to
//     - this needs to be done here becase once we move the ant it gets set
//     - to 1 and then the loop breaks.
// change the way the ant is facing
// sets the ant on the new tile.
void Ant::moveAntRight() {
  int currentTile = 0;
  switch(directionFacing) {
  case 'U':
    cout << "u - HERE";
    swapColors();
    posY++;
    if(posY >= maxY) {
      posY = 0;
    }
    currentTile = board[posX][posY];
    setTileColor(currentTile);
    setAntFacing('R');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'D':
    cout << "d - here";
    swapColors();
    posY--;
    if(posY < 0) {
      posY = (maxY - 1);
    }
    currentTile = board[posX][posY];
    setTileColor(currentTile);
    setAntFacing('L');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'L':
    cout << "l - here";
    swapColors();
    posX--;
    if(posX < 0) {
      posX = (maxX - 1);
    }
    currentTile = board[posX][posY];
    setTileColor(currentTile);
    setAntFacing('U');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'R':
    cout << "r - here";
    swapColors();
    posX++;
    if(posX >= maxX) {
      posX = 0;
    }
    currentTile = board[posX][posY];
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
    posY--;
    if(posY < 0) {
      posY = (maxY - 1);
    }
    currentTile = board[posX][posY];
    setTileColor(currentTile);
    setAntFacing('L');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'D':
    swapColors();
    posY++;
    if(posY >= maxY) {
      posY = 0;
    }
    currentTile = board[posX][posY];
    setTileColor(currentTile);
    setAntFacing('R');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'L':
    swapColors();
    posX++;
    if(posX >= maxX) {
      posX = 0;
    }
    currentTile = board[posX][posY];
    setTileColor(currentTile);
    setAntFacing('D');
    board[getXPosition()][getYPosition()] = 1;
    break;
  case 'R':
    swapColors();
    posX--;
    if(posX < 0) {
      posX = (maxX - 1);
    }
    currentTile = board[posX][posY];
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
    board[posX][posY] = 2;
  } else {
    board[posX][posY] = 0;
  }
}

void Ant::leftRightCollision() {

  if(posX > maxX) {
    setXPosition(0);
  } else if(posX < 0) {
    setXPosition(maxX);
  } else {
    posY++;
  }
}
void Ant::upDownCollision() { return; }
