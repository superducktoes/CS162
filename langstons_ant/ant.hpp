
#ifndef ANT_HPP
#define ANT_HPP

class Ant {
private:
  int posX;
  int posY;
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

  //need to go through this and comment/make sure still in use
  void setBoard(int**);
  int** getBoard();
  void setXPosition(int);
  void setYPosition(int);
  int getXPosition();
  int getYPosition();
  void setMaxXPosition(int);
  void setMaxYPosition(int);
  int getMaxXPosition();
  int getMaxYPosition();
  void moveAnt();
  void moveAntLeft();
  void moveAntRight();
  void setAntFacing(char);
  char getAntFacing();
  void setAntMoves(int);
  int getAntMoves();
  void setTileColor(int);
  int getTileColor();
  void swapColors();
  void collisionChecker();
};

#endif
