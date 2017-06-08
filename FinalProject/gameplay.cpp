#include "gameplay.hpp"
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

GamePlay::GamePlay(string n) {
  parkingLot = new ParkingLot("parkinglot");
  mainLobby = new MainLobby("mainlobby");
  parkingLot->linkRoom(mainLobby,'r');
  mainLobby->linkRoom(parkingLot, 'l');
  currentLocation = parkingLot;

  playerName = n;
  gameOver = false;
  turnCounter = 0;
}
// keeps track of the number of turns the player took and then suggest hints
void GamePlay::gameHints() {
  if(turnCounter == 9) {
    cout << "If you haven't looked in the parking lot already there may be " 
	 << "something out there that you can use. " << endl;
  }
}

// when exploring a room we can add to the players items here.
// https://stackoverflow.com/questions/571394/how-to-find-if-an-item-is-present-in-a-stdvector
void GamePlay::exploreRoom(string room) {
  if(room == "parkinglot") {
    if(std::find(playerInventory.begin(),playerInventory.end(), "usb stick") != playerInventory.end()) {
      cout << "It doesn't look like there's anything else out here other than "
      	   << "a few cars and some newspapers blowing in the wind. " << endl;
    } else {
      cout << "looks there's a usb stick out here.\n "
	   << "Let's add this to our inventory. " << endl;
      playerInventory.push_back("usb stick");
    }
  } // cloes the room
}

void interactRoom(string room) {
  cout << room;
}

void GamePlay::startGame() {
  char direction;
  do {
    
    direction = currentLocation->playRoom();
    // get the direction to move in next
    if(direction == 'r') {
      currentLocation = currentLocation->getRightRoom();
    } else if(direction == 'l') {
      currentLocation = currentLocation->getLeftRoom();
    } else if(direction == 'x') {
      string roomName = currentLocation->getRoomName();
      exploreRoom(roomName);
    }
    turnCounter++;
    gameHints();
  } while(direction != 'q');
  cout << "thanks for playing!" << endl; 
}
