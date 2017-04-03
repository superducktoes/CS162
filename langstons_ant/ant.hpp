#ifndef ANT_HPP
#define ANT_HPP

class Ant {
private:
  int posX;
  int posY;
  int** board;
public:
  Ant(int** board,int x, int y) {
    setXPosition(x);
    setYPosition(y);
    board[getXPosition()][getYPosition()] = 1;
  }
  void setBoard(int**);
  int** getBoard();
  void setXPosition(int);
  void setYPosition(int);
  int getXPosition();
  int getYPosition();
  int getCurrentColor();
};

#endif
