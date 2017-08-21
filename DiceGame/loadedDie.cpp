/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/23/2017
  * Description: LoadedDie subclass. Inherits from the dice superclass
  *
  *****************************************************************************/
#include "loadedDie.hpp"
#include <time.h>
#include <cstdlib>
#include <iostream>

// tried to make this loaded but still give the other player a chance if they are using an unloaded dice
// rolls the dice a number of times based off of the sides and has a weighted rng

int LoadedDie::returnLoadedRoll() {

  int randomTotal = sides;
  int randomInt = (rand()%sides+1);

  if( (sides - randomInt) < (sides / 2) ) {
    randomTotal = randomInt;
  } else {
    randomTotal = (sides - randomInt);
  }

  return randomTotal;

}
