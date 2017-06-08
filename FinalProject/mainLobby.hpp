#ifndef MAINLOBBY_HPP
#define MAINLOBBY_HPP
#include "defaultRoom.hpp"

class MainLobby : public defaultRoom {
public:
  MainLobby(std::string n) : defaultRoom(n) {};
  char playRoom();
};
#endif
