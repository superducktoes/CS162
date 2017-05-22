/************************************************
 *
 * Author: Nick Roy
 * Date: 5/14/2017
 * Description: Blue men class. Loses one dice for every 4 damage points
 *
 **********************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "creature.hpp"

class BlueMen: public Creature {
public:
  BlueMen(string s) : Creature(s) {};
  int attackRollDie();
  int defendRollDie(int);
};

#endif
