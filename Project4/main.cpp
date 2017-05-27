/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 5/27/2017
  *
  * Description: Project 4 extends project 3 and adds a tournament style gameplay.
  * Includes files from project 3 as well as some lines of code from labs 6 and 7 for the
  * stack and queue functions.
  *
  * In the game eachplayer is prompter to pick their lineup of monsters and then
  * the game will automatically play for each player. Once the games are done the
  * winner will be displayed and the score. Players will be prompted to play again
  * or quit after that and show the losing monsters.
  *
  *****************************************************************************/
  
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
      playNewGame.showLosingMonsters();
    }
  } while (carryOn == true);
  return 0;
}
