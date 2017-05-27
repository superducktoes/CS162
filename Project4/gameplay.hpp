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
