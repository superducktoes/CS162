#include "gameplay.hpp"
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;


GamePlay::GamePlay(string n) {
  //lets link all of the rooms together
  parkingLot = new ParkingLot("parkinglot");
  mainLobby = new MainLobby("mainlobby");
  reception = new Reception("reception");
  yourdesk = new YourDesk("yourdesk");
  darkhallway = new DarkHallway("darkhallway");
  bossoffice = new BossOffice("bossoffice");
  breakroom = new BreakRoom("breakroom");

  parkingLot->linkRoom(mainLobby,'r');
  mainLobby->linkRoom(parkingLot, 'l');
  mainLobby->linkRoom(reception,'r');
  reception->linkRoom(mainLobby,'l');
  reception->linkRoom(yourdesk,'u');
  yourdesk->linkRoom(reception,'d');
  reception->linkRoom(darkhallway,'d');
  darkhallway->linkRoom(reception,'u');
  darkhallway->linkRoom(bossoffice,'l');
  bossoffice->linkRoom(darkhallway,'r');
  bossoffice->linkRoom(breakroom,'l');
  breakroom->linkRoom(bossoffice,'r');

  currentLocation = mainLobby;

  // some information about the player
  playerName = n;
  turnCounter = 0;
  carryOn = true;
  usbPluggedIn = false;
  foundUsbStick = false;
  foundCoffeeCup = false;
}
// keeps track of the number of turns the player took and then suggest hints
void GamePlay::gameHints() {
  // keep track if the game is still going. if not the hints will be displayed after the player wins the game
  if(carryOn == true) {
    if(turnCounter == 9 && foundUsbStick == false) {
      cout << "\n\n*** If you haven't looked in the parking lot already there may be "
	   << "something out there that you can use ***\n\n" << endl;
    } else if(turnCounter == 14 && usbPluggedIn == false) {
      cout << "\n\n*** Explore the parking lot and then see if there's somewhere at the desk you can plugh it in ***\n\n" << endl;
    } else if(turnCounter == 22) {
      cout << "\n\n*** After taking the usb from the parking lot to your desk check out your boss's office ***\n\n";
    }
  }
}

// when exploring a room we can add to the players items here.
// https://stackoverflow.com/questions/571394/how-to-find-if-an-item-is-present-in-a-stdvector
void GamePlay::exploreRoom(string room) {
  if(room == "parkinglot") {
    if(std::find(playerInventory.begin(),playerInventory.end(), "usb stick") != playerInventory.end()) {
      cout << "\nIt doesn't look like there's anything else out here other than "
      	   << "a few cars and some newspapers blowing in the wind. " << endl;
    } else {
      cout << "\nlooks there's a usb stick out here.\n "
	   << "Let's add this to our inventory. " << endl;
      playerInventory.push_back("usb stick");
      foundUsbStick = true;
    }
  } else if(room == "bossoffice") {
    if(usbPluggedIn == true) {
      cout << "\nAHA! Found the coffee mug! Let's take this to the breakroom. " << endl;
      playerInventory.push_back("coffee mug");
      foundCoffeeCup = true;
    } else {
      cout << "\nI don't think I have a good enough reason to look in there yet. Maybe I should start a little work at my desk... " << endl;
    }
  }
}

// if a player chooses to explore a room and they have an object they can use the object to further unlock the game
// if there is nothing to add to a player's inventory in the room then the room will not call this function.
void GamePlay::interactRoom(string room) {
  if(room == "yourdesk") {
    if(foundUsbStick == false) {
      cout << "\nThe warm glow of your monitor welcomes you back to your desk. " << endl;
      cout << "There's some papers on your desk from last Friday, not sure what they were for. " << endl;
      cout << "Looking them over it looks like I didn't write down where I put my coffee mug. " << endl;
    } else if(foundUsbStick == true) {
      cout << "\nLet's plug this usb stick into the computer. " << endl;
      cout << "Aha! That's right, I left my coffee in the bosses office last Friday. " << endl;
      usbPluggedIn = true;
    }
  } else if(room == "breakroom") {
    if(foundCoffeeCup == true) {
      cout << "\nFinally found our coffee mug and now for some sweet coffee! " << endl;
      cout << "Congratulations! You won the game! " << endl;
      cout << "Finished the game in " << (turnCounter + 1) << " moves. " << endl;
      carryOn = false;
    } else {
      cout << "\nGlad we found the source of the coffee but we don't have our mug yet to get the coffee. " << endl;
    }
  }
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
    } else if(direction == 'u') {
      currentLocation = currentLocation->getUpRoom();
    } else if(direction == 'd') {
      currentLocation = currentLocation->getDownRoom();
    } else if(direction == 'x') {
      string roomName = currentLocation->getRoomName();
      exploreRoom(roomName);
    } else if(direction == 'i') {
      string roomName = currentLocation->getRoomName();
      interactRoom(roomName);
    }
    turnCounter++;
    gameHints();

    // im sure there's a good reason this doesnt work in a do-while
    if(carryOn == false) {
      direction = 'q';
    }
  } while(direction != 'q');
  cout << "Thanks for playing!" << endl;

  //deallocate the memory
  delete parkingLot;
  delete mainLobby;
  delete reception;
  delete yourdesk;
  delete darkhallway;
  delete bossoffice;
  delete breakroom;

}
