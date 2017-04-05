#include "ant.hpp"

void Ant::setBoard(int** board) {
  board = board;
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

void Ant::setMaxXPosition(int maxX) {
  maxX = maxX;
}

void Ant::setMaxYPosition(int maxY) {
  maxY = maxY;
}

int Ant::getMaxXPosition() {
  return maxX;
}

int Ant::getMaxYPosition() {
  return maxY;
}

// returns 0 if white 2 if black
int Ant::getCurrentColor() {
  int color;
  color = board[getXPosition()][getYPosition()];
  return color;
}

// this is the main part of the ant's movement. we need to find out first
// what colored square the ant is on and then move accordingly.
// 0's are white squares, 1's are black squares.
void Ant::moveAnt() {
  // we need to find out what color square the ant is on to determine his move
  int currentColor = getCurrentColor();

  if(currentColor = 0) {
    //if it's a white square we need to move right
    moveAntRight();
  } else if(currentColor = 2) {
    //if it's a black square we need to move left
    moveAntLeft();
  }
  
}

void Ant::moveAntLeft() { return; }
void Ant::moveAntRight() {return; }
// sets the direction that the ant is facing. Will be a char that is either
// U, D, L, R
void Ant::setAntFacing(char s) {
  directionFacing = s;
}
char Ant::getAntFacing() {
  return directionFacing;
}

