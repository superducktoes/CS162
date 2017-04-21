/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/23/2017
  * Description: Dice superclass. Default constructor takes the number of
  * sides from the user to generate it. generateRoll() function generates
  * a random number for the roll of the dice.
  *
  *****************************************************************************/
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
