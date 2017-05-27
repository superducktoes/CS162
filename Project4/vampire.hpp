/************************************************
 *
 * Author: Nick Roy
 * Date: 5/14/2017
 * Description: Vampire has a 50% chance of taking no damage from an attack
 *
 **********************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "creature.hpp"

class Vampire: public Creature {
public:
  Vampire(string s, string p) : Creature(s,p) {};
  int attackRollDie();
  int defendRollDie(int);
};

#endif
