#ifndef DEFAULTROOM_HPP
#define DEFAULTROOM_HPP
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class defaultRoom {
protected:
  defaultRoom* right;
  defaultRoom* left;
  defaultRoom* up;
  defaultRoom* down;

  string roomName;
  int userChoice;
public:
  defaultRoom(string);
  virtual char playRoom() = 0;
  void linkRoom(defaultRoom*, char);
  defaultRoom* getLeftRoom() { return left; }
  defaultRoom* getRightRoom() { return right; }
  defaultRoom* getUpRoom() { return up; }
  defaultRoom* getDownRoom() { return down; }
  string getRoomName() { return roomName; }
};

#endif
