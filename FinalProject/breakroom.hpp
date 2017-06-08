#ifndef BREAKROOM_HPP
#define BREAKROOM_HPP
#include "defaultRoom.hpp"

class BreakRoom : public defaultRoom {
public:
  BreakRoom(std::string n) : defaultRoom(n) {};
  char playRoom();
};
#endif
