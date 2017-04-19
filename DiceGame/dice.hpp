/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/23/2017
  * Description: Dice superclass. Default constructor takes the number of
  * sides from the user to generate it. generateRoll() function generates
  * a random number for the roll of the dice.
  *
  *****************************************************************************/
#ifndef DICE_HPP
#define DICE_HPP
#include <time.h>
#include <cstdlib>

class Dice {
private:
  int numberOfSides;
  int diceValue;
public:
  Dice(int s)
  : numberOfSides(s)
  {
    // this needs to stay here to make sure that the random number is only
    // seeded once: http://stackoverflow.com/questions/33711219/random-number-generator-function-in-class
    unsigned seed = time(0);
    srand(seed);
    diceValue = 0;
  }
  int generateRoll();
};
#endif
