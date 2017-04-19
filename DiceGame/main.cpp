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

  cout << "How many sides would you like on your die player one? ";
  cin >> playerOneDieSides;
  cout << "And is player one's dice a loaded dice? (L or U) ";
  cin >> playerOneLoaded;
  cout << "How many sides would you like on your die player two? ";
  cin >> playerTwoDieSides;
  cout << "And is player two's dice a loaded dice? (L or U) ";
  cin >> playerTwoLoaded;

  cout << "And the final question, how many rounds would you like to play? ";
  cin >> numberOfTurns;

  Game diceGame(numberOfTurns, playerOneDieSides, playerTwoDieSides, playerOneLoaded, playerTwoLoaded);
  diceGame.startGame();

  return 0;
}
