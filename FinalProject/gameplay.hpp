#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include<vector>
#include<iostream>
using std::string;

#include "parkingLot.hpp"
#include "mainLobby.hpp"

class GamePlay {
private:
  defaultRoom* parkingLot;
  defaultRoom* mainLobby;
  defaultRoom* currentLocation;

  string playerName;
  bool gameOver;
  std::vector<string> playerInventory;
  int turnCounter;
public:
  GamePlay(string n);
  void startGame();
  void gameHints();
  void exploreRoom(string);
  //need one more public function to interact with a room
  //this will be able to search the vector of items and use them.
  //needs to be different rooms from where a player can find items.
  void interactRoom(string);
};
#endif
