/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/23/2017
  * Description: LoadedDie subclass. Inherits from the dice superclass
  *
  *****************************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "dice.hpp"
#include <time.h>
#include <cstdlib>

class LoadedDie : public Dice {
public:
  LoadedDie(int s)
  : Dice(s)
  {
  }
  int returnLoadedRoll();
};
#endif
