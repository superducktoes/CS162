/************************************************
 *
 * Author: Nick Roy
 * Date: 4/6/2017
 * Description: Header file for the ant class
 *
 **********************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant {
private:
  int posY;
  int posX;
  int** board;
  int maxX;
  int maxY;
  char directionFacing; //used to keep track of the direction the ant is facing
  int antMoves;
  int antTileColor;
public:
  Ant(int** b,int x, int y, int maxX, int maxY, int moves) {
    setBoard(b);
    setXPosition(x);
    setYPosition(y);
    setMaxXPosition(maxX);
    setMaxYPosition(maxY);
    setAntFacing('U');
    setAntMoves(moves);
    board[getXPosition()][getYPosition()] = 1;
    setTileColor(0);
  }

  void setBoard(int**);
  void setXPosition(int);
  void setYPosition(int);
  int getXPosition();
  int getYPosition();
  void setMaxXPosition(int);
  void setMaxYPosition(int);
  void moveAnt();
  void moveAntLeft();
  void moveAntRight();
  void setAntFacing(char);
  void setAntMoves(int);
  void setTileColor(int);
  int getTileColor();
  void swapColors();
  void collisionChecker();
};

#endif
