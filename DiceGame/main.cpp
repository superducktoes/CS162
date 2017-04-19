/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/23/2017
  * Description: Main file for the dice game.
  *
  *****************************************************************************/
#include <iostream>
#include "game.hpp"
using std::cout;
using std::cin;
using std::endl;

int main() {

  int numberOfTurns;
  int playerOneDieSides;
  int playerTwoDieSides;
  char playerOneLoaded;
  char playerTwoLoaded;

  // lets add some more thrilling menu options here later...
  std::cout << "Welcome to the dice game" << '\n';
  std::cout << "this is the start of a new game!" << '\n';
  std::cout << "Players, you will be asked to pick whether you want a loaded or unloaded dice." << endl;
  std::cout << "Loaded dice will give you better odds of getting a higher roll." << endl;
  std::cout << "Each player will also decide how many sides their dice has." << endl;
  std::cout << "\n";

  // gets the inputs from the two Players
  cout << "How many sides would you like on your die player one? ";
  cin >> playerOneDieSides;
  cout << "And is player one's dice a loaded or unloaded dice? (L or U) ";
  cin >> playerOneLoaded;
  cout << "How many sides would you like on your die player two? ";
  cin >> playerTwoDieSides;
  cout << "And is player two's dice a loaded or unloaded dice? (L or U) ";
  cin >> playerTwoLoaded;

  cout << "And the final question, how many rounds would you like to play? ";
  cin >> numberOfTurns;

  // initiates the game object and then starts it
  Game diceGame(numberOfTurns, playerOneDieSides, playerTwoDieSides, playerOneLoaded, playerTwoLoaded);
  diceGame.startGame();

  return 0;
}
