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

// returns 0 if white 2 if black
int Ant::getCurrentColor() {
  int color;
  color = board[getXPosition()][getYPosition()];
  return color;
}
