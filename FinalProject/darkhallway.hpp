#ifndef DARKHALLWAY_HPP
#define DARKHALLWAY_HPP
#include "defaultRoom.hpp"

class DarkHallway : public defaultRoom {
public:
  DarkHallway(std::string n) : defaultRoom(n) {};
  char playRoom();
};
#endif
