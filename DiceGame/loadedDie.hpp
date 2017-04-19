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
    unsigned seed = time(0);
    srand(seed);
  }
  int returnLoadedRoll();
};
#endif
