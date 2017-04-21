/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/23/2017
  * Description: Game class creates two dice and is instantiated using the
  * number of turns, sides on the dice, and whether or not they are loaded
  * dice.
  *
  *****************************************************************************/
#include <iostream>
#include "game.hpp"
#include "dice.hpp"
#include "loadedDie.hpp"
#include "menu.hpp"
using std::cout;
using std::endl;

void Game::startGame() {
  int counter = 0; // used to track the current round
  cout << "The game has been started!" << endl;
  // keep this here to clear out the input buffer
  std::cin.ignore();
  // this covers each player having unloaded dice
  if(playerOneLoaded == 'u' && playerTwoLoaded == 'u') {
    cout << "Both players are using unloaded dice" << endl;

    Dice p1(dieOneSides);
    Dice p2(dieTwoSides);

    do {
      int p1Die = p1.generateRoll();
      int p2Die = p2.generateRoll();
      cout << "\nPlayer One rolls: " << p1Die << " Player Two rolls: " << p2Die << endl;
      if(p1Die > p2Die) {
          cout << "Player One Wins!";
          playerOneScore++;
        } else if(p2Die > p1Die) {
          cout << "Player Two Wins!";
          playerTwoScore++;
        } else {
          cout << "The game is a tie!";
        }
        blankEnter();
        counter++;
    } while( counter < turns);

  } else if(playerOneLoaded == 'u' && playerTwoLoaded == 'l') {
    cout << "Player one has an unloaded dice and player two has a loaded dice" << endl;

    Dice p1(dieOneSides);
    LoadedDie p2(dieTwoSides);

    do {
      int p1Die = p1.generateRoll();
      int p2Die = p2.returnLoadedRoll();
      cout << "\nPlayer One rolls: " << p1Die << " Player Two rolls: " << p2Die << endl;
      if(p1Die > p2Die) {
          cout << "Player One Wins!";
          playerOneScore++;
        } else if(p2Die > p1Die) {
          cout << "Player Two Wins!";
          playerTwoScore++;
        } else {
          cout << "The game is a tie!";
        }
        blankEnter();
        counter++;
    } while( counter < turns);

  } else if(playerOneLoaded == 'l' && playerTwoLoaded == 'u') {
    cout << "Player one has a loaded die and player two has an unloaded die" << endl;

    LoadedDie p1(dieOneSides);
    Dice p2(dieTwoSides);

    do {
      int p2Die = p2.generateRoll();
      int p1Die = p1.returnLoadedRoll();

      cout << "\nPlayer One rolls: " << p1Die << " Player Two rolls: " << p2Die << endl;
      if(p1Die > p2Die) {
          cout << "Player One Wins!";
          playerOneScore++;
        } else if(p2Die > p1Die) {
          cout << "Player Two Wins!";
          playerTwoScore++;
        } else {
          cout << "The game is a tie!";
        }
        blankEnter();
        counter++;
    } while( counter < turns);

  } else {
    cout << "Both players are using loaded die!" << endl;

    LoadedDie p1(dieOneSides);
    LoadedDie p2(dieTwoSides);

    do {
      int p2Die = p2.returnLoadedRoll();
      int p1Die = p1.returnLoadedRoll();

      cout << "\nPlayer One rolls: " << p1Die << " Player Two rolls: " << p2Die << endl;
      if(p1Die > p2Die) {
          cout << "Player One Wins!";
          playerOneScore++;
        } else if(p2Die > p1Die) {
          cout << "Player Two Wins!";
          playerTwoScore++;
        } else {
          cout << "The game is a tie!";
        }
        blankEnter();
        counter++;
    } while( counter < turns);
  }

  if(playerOneScore > playerTwoScore) {
    cout << "\nPLAYER ONE WINS!" << endl;
  } else if(playerTwoScore > playerOneScore) {
    cout << "\nPLAYER TWO WINS!" << endl;
  } else {
    cout << "\nTHE GAME IS A DRAW!" << endl;
  }
}

Game::~Game() {
  cout << "Thanks for playing" << endl;
  playerOneScore = playerTwoScore = 0;
}
