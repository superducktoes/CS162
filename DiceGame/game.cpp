#include <iostream>
#include "game.hpp"
using std::cout;
using std::endl;

void Game::startGame() {
  cout << "The game has been started!";
  if(playerOneLoaded == 'U' && playerTwoLoaded == 'U') {
    cout << "Both players are using unloaded dice" << endl;
    int counter = 0; // used to track the current round
    Dice p1(dieOneSides);
    Dice p2(dieTwoSides);
    // lets make an if-else to decide on whether or not to generate a loaded or unloaded roll
    char c;
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
        cout << "\n\nenter a character to continue";
        std::cin >> c;
        counter++;
    } while( counter < turns);
  }

  if(playerOneScore > playerTwoScore) {
    cout << "PLAYER ONE WINS!";
  } else if(playerTwoScore > playerOneScore) {
    cout << "PLAYER TWO WINS!";
  } else {
    cout << "THE GAME IS A DRAW!";
  }
}
