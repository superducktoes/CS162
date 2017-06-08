#ifndef RECEPTION_HPP
#define RECEPTION_HPP
#include "defaultRoom.hpp"

class Reception : public defaultRoom {
public:
  Reception(std::string n) : defaultRoom(n) {};
  char playRoom();
};
#endif
