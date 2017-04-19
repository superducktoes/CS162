#include "dice.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>
using std::cout;
using std::endl;

// not much else a dice has to do other than roll
int Dice::generateRoll() {
  diceValue = 1 + rand() % numberOfSides;
  return diceValue;
}
