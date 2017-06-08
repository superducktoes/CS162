#include <iostream>
#include "gameplay.hpp"
using namespace std;

int main() {

  string playerName;

  cout << "You are the brave adventurer that is having to get into the office "
       << "on a monday morning and get to your coffee. " << endl;
  cout << "The goal of this program is to search the office for your coffee " 
       << "mug and get to the coffee maker in the break room. " << endl;

  cout << "Let's start off with your name: ";
  cin >> playerName;
  
  cout << "Let's begin our adventure " << playerName << endl;
  GamePlay newGame(playerName);
  newGame.startGame();

  return 0;
}
