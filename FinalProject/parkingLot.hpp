#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP
#include "defaultRoom.hpp"

class ParkingLot : public defaultRoom {
public:
  ParkingLot(std::string n) : defaultRoom(n) {};
  char playRoom();
};
#endif
