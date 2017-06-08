#include "defaultRoom.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

defaultRoom::defaultRoom(string n) {
  if(n == "parkinglot") {
    roomName = n;
  } else if(n == "mainlobby") {
    roomName = n;
  }
  
  right = NULL;
  left = NULL;
  up = NULL;
  down = NULL;
}

//this is where we link the rooms
void defaultRoom::linkRoom(defaultRoom* r, char d) {
  if(d == 'r') {
    right = r;
  } else if(d == 'l') {
    left = r;
  } else if(d == 'u') {
    up = r;
  } else if(d == 'd') {
    down = r;
  }
}
