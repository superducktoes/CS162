#include <iostream>
#include "game.hpp"
#include "dice.hpp"
#include "loadedDie.hpp"
#include "menu.hpp"
using std::cout;
using std::endl;

void Game::startGame() {
  int counter = 0; // used to track the current round
  cout << "The game has been started!";
  // this covers each player having unloaded dice
  if(playerOneLoaded == 'U' && playerTwoLoaded == 'U') {
    cout << "Both players are using unloaded dice" << endl;

    Dice p1(dieOneSides);
    Dice p2(dieTwoSides);

    do {
      int p1Die = p1.generateRoll();
      int p2Die = p2.generateRoll();
      cout << "Player One rolls: " << p1Die << " Player Two rolls: " << p2Die << endl;
      if(p1Die > p2Die) {
          cout << "Player One Wins!";
          playerOneScore++;
        } else if(p2Die > p1Die) {
          cout << "Player Two Wins!";
          playerTwoScore;
        } else {
          cout << "The game is a tie!";
        }
        blankEnter();
        counter++;
    } while( counter < turns);

  } else if(playerOneLoaded == 'U' && playerTwoLoaded == 'L') {
    cout << "Player one has an unloaded dice and player two has a loaded dice" << endl;

    Dice p1(dieOneSides);
    LoadedDie p2(dieTwoSides);

    do {
      int p1Die = p1.generateRoll();
      int p2Die = p2.returnLoadedRoll();
      cout << "Player One rolls: " << p1Die << " Player Two rolls: " << p2Die << endl;
      if(p1Die > p2Die) {
          cout << "Player One Wins!";
          playerOneScore++;
        } else if(p2Die > p1Die) {
          cout << "Player Two Wins!";
          playerTwoScore;
        } else {
          cout << "The game is a tie!";
        }
        blankEnter();
        counter++;
    } while( counter < turns);

  } else if(playerOneLoaded == 'L' && playerTwoLoaded == 'U') {
    cout << "Player one has a loaded die and player two has an unloaded die" << endl;

    LoadedDie p1(dieOneSides);
    Dice p2(dieTwoSides);

    do {
      int p2Die = p2.generateRoll();
      int p1Die = p1.returnLoadedRoll();

      cout << "Player One rolls: " << p1Die << " Player Two rolls: " << p2Die << endl;
      if(p1Die > p2Die) {
          cout << "Player One Wins!";
          playerOneScore++;
        } else if(p2Die > p1Die) {
          cout << "Player Two Wins!";
          playerTwoScore;
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

      cout << "Player One rolls: " << p1Die << " Player Two rolls: " << p2Die << endl;
      if(p1Die > p2Die) {
          cout << "Player One Wins!";
          playerOneScore++;
        } else if(p2Die > p1Die) {
          cout << "Player Two Wins!";
          playerTwoScore;
        } else {
          cout << "The game is a tie!";
        }
        blankEnter();
        counter++;
    } while( counter < turns);
  }

  // checks at the end to see who had the higher score
  if(playerOneScore > playerTwoScore) {
    cout << "PLAYER ONE WINS!";
  } else if(playerTwoScore > playerOneScore) {
    cout << "PLAYER TWO WINS!";
  } else {
    cout << "THE GAME IS A DRAW!";
  }
}
