/************************************************************************
 *
 * Author: Nick Roy
 * Date: 4/6/2017
 * Description: Ant class. Builds the ant and handles the decision making
 * for what happens when turning left/right based on the white/black 
 * square that it is on.
 *
 ************************************************************************/

#include <iostream>
#include "ant.hpp"

using std::cout;
using std::endl;

// from the board we build
void Ant::setBoard(int** b) {
  board = b;
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

void Ant::setAntMoves(int m) {
  antMoves = m;
}

// sets the next tile color
void Ant::setTileColor(int c) {
  antTileColor = c;
}

// gets the color of the tile the ant is on
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

// same as above just differnt orientations based on turning left
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

// runs with each movement iteration. depending on whether the ant moved left/right or up/down
// it checks to see if the ant is at the max or 0 and then wraps around to the other side.
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
