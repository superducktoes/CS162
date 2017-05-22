/************************************************
 *
 * Author: Nick Roy
 * Date: 5/14/2017
 * Description: Barbarian class.
 *
 **********************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "creature.hpp"

class Barbarian: public Creature {
public:
  Barbarian(string s) : Creature(s) {};
  int attackRollDie();
  int defendRollDie(int);
};

#endif
