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
