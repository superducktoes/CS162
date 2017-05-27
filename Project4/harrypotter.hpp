/************************************************
 *
 * Author: Nick Roy
 * Date: 5/14/2017
 * Description: Harry Potter. Regenerates with double health after dying the
 * first time
 *
 **********************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "creature.hpp"

class HarryPotter: public Creature {
private:
  bool regenerate = true;
public:
  HarryPotter(string s,string p) : Creature(s,p) {};
  int attackRollDie();
  int defendRollDie(int);
};

#endif
