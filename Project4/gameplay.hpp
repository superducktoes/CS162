/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 5/27/2017
  *
  * Description: Gameplay is responsible for running through the battles and has
  * two additional functions for comparing the scores at the end and showing the
  * monsters in the losing stack.
  *
  *****************************************************************************/

#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "monsterstack.hpp"

class Gameplay {
private:
  int playerOneScore;
  int playerTwoScore;
  MonsterStack loserStack;
public:
  void playGame();
  void compareScore();
  void showLosingMonsters();
};
#endif
