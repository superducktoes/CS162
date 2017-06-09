#include "defaultRoom.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// default constructor creates a room with a name for the room. this name acts as a key
// to identify the room the player is in if they are exploring or interacting with the room.
// additional attributes can be added to the room as needed.
defaultRoom::defaultRoom(string n) {
  if(n == "parkinglot") {
    roomName = n;
  } else if(n == "mainlobby") {
    roomName = n;
  } else if(n == "reception") {
    roomName = n;
  } else if(n == "yourdesk") {
    roomName = n;
  } else if(n == "darkhallway") {
    roomName = n;
  } else if(n == "bossoffice") {
    roomName = n;
  } else if(n == "breakroom") {
    roomName = n;
  }

  right = NULL;
  left = NULL;
  up = NULL;
  down = NULL;
}

//link the rooms
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
