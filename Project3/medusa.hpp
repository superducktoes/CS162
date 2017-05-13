/************************************************
 *
 * Author: Nick Roy
 * Date: 5/14/2017
 * Description: Medusa generates a glare attack when rolling a 12 which kills
 * most enemies instantly except for Harry Potter and the Vampire
 *
 **********************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "creature.hpp"

class Medusa: public Creature {

public:
  Medusa(string s) : Creature(s) {};
  int attackRollDie();
  int defendRollDie(int);
};

#endif
