#include "loadedDie.hpp"
#include <time.h>
#include <cstdlib>
#include <iostream>

// This still feels a little ugly. takes the number of sides on the dice and cuts that in half
// then it generates that many random numbers and divides it by the cut in half sides
// gives pretty okay results for late at night...

int LoadedDie::returnLoadedRoll() {

  int tempNum = 0;
  int halfSides = (numberOfSides/2);

  for(int i = 0; i < halfSides; i++) {
    tempNum += 1 + rand() % numberOfSides;
  }

  tempNum = (tempNum/halfSides);

  return tempNum;
}
