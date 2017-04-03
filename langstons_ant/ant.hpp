
#ifndef ANT_HPP
#define ANT_HPP

class Ant {
private:
  int posX;
  int posY;
  int** board;
  int maxX;
  int maxY;
public:
  Ant(int** board,int x, int y, int maxX, int maxY) {
    setXPosition(x);
    setYPosition(y);
    setMaxXPosition(maxX);
    setMaxYPosition(maxY);
    board[getXPosition()][getYPosition()] = 1;
  }
  void setBoard(int**);
  int** getBoard();
  void setXPosition(int);
  void setYPosition(int);
  int getXPosition();
  int getYPosition();
  int getCurrentColor();
  void setMaxXPosition(int);
  void setMaxYPosition(int);
  int getMaxXPosition();
  int getMaxYPosition();
};

#endif
