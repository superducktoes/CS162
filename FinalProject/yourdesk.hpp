#ifndef YOURDESK_HPP
#define YOURDESK_HPP
#include "defaultRoom.hpp"

class YourDesk : public defaultRoom {
public:
  YourDesk(std::string n) : defaultRoom(n) {};
  char playRoom();
};
#endif
