/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/23/2017
  * Description: Main file for the dice game.
  *
  *****************************************************************************/
#include <iostream>
#include "game.hpp"
#include "menu.hpp"
#include <time.h>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

int main() {

  // variables for the dice and number of turns to play
  int numberOfTurns;
  int playerOneDieSides;
  int playerTwoDieSides;
  char playerOneLoaded;
  char playerTwoLoaded;
  char keepPlaying = 'y';

  // this needs to stay here to make sure that the random number is only
  // seeded once: http://stackoverflow.com/questions/33711219/random-number-generator-function-in-class
  srand ( time(NULL) );

  do {
    cout << "Welcome to the dice game" << '\n';
    cout << "this is the start of a new game!" << '\n';
    cout << "Players, you will be asked to pick whether you want a loaded or unloaded dice." << endl;
    cout << "Loaded dice will give you better odds of getting a higher roll." << endl;
    cout << "Each player will also decide how many sides their dice has." << endl;
    cout << "\n";

    // gets the inputs from the two Players
    playerOneDieSides = checkNumber("How many side would you like on your dice player one? ");
    playerOneLoaded = checkCharacter("And is player one's dice a loaded or unloaded dice? (L or U) ", 'L','U');
    playerTwoDieSides = checkNumber("How many side would you like on your dice player two? ");
    playerTwoLoaded = checkCharacter("And is player two's dice a loaded or unloaded dice? (L or U) ", 'L','U');

    numberOfTurns = checkNumber("And the final question, how many rounds would you like to play? ");

    // initiates the game object and then starts it
    Game diceGame(numberOfTurns, playerOneDieSides, playerTwoDieSides, playerOneLoaded, playerTwoLoaded);
    diceGame.startGame();

    // now that the game is over let's prompt the user to see if they want to keep playing
    keepPlaying = menuPlayOn();
  } while(keepPlaying == 'y');
  return 0;
}
