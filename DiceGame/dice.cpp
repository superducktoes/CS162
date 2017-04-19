#include "dice.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>
using std::cout;
using std::endl;

int Dice::generateRoll() {
  diceValue = 1 + rand() % numberOfSides;
  return diceValue;
}
