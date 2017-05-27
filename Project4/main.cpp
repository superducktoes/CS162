#include <iostream>
#include "gameplay.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

  Gameplay playNewGame;
  bool carryOn = true;
  int userChoice;

  do {
    playNewGame.playGame();
    playNewGame.compareScore();
    cout << "The game is finished. " << endl;
    cout << "Enter 1 to show the losing monsters and play again. " << endl;
    cout << "Or enter 2 to show the losing monsters and quit the game. " << endl;
    cin >> userChoice;

    if(userChoice == 1) {
      cout << "The monsters that lost in the tournament are: " << endl;
      playNewGame.showLosingMonsters();
    } else if(userChoice == 2) {
      playNewGame.showLosingMonsters();
      cout << "Thanks for playing! " << endl;
      carryOn = false;
    } else {
      cout << "Invalid entry... Restarting game " << endl;
    }
  } while (carryOn == true);
  return 0;
}
