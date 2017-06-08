#ifndef BOSSOFFICE_HPP
#define BOSSOFFICE_HPP
#include "defaultRoom.hpp"

class BossOffice : public defaultRoom {
public:
  BossOffice(std::string n) : defaultRoom(n) {};
  char playRoom();
};
#endif
