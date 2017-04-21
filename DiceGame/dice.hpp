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
  int diceValue;
protected:
  int numberOfSides;
public:

  Dice(int s)
  : numberOfSides(s)
  {

    diceValue = 0;
  }
  int generateRoll();
};
#endif
