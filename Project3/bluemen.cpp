#include <iostream>

#include "creature.hpp"
#include "bluemen.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;

int BlueMen::attackRollDie() {
  int attackDieOne = 1 + rand() % 10;
  int attackDieTwo = 1 + rand() % 10;
  int attackRollDie = (attackDieOne + attackDieTwo);

  return attackRollDie;
}

int BlueMen::defendRollDie(int a) {
  int defendDieOne = 1 + rand() % 6;
  int defendDieTwo = 1 + rand() % 6;
  int defendDieThree = 1 + rand() % 6;
  int totalDefendScore = (defendDieOne + defendDieTwo + defendDieThree) + this->creatureArmor;
  int tempStrength = this->creatureStrength;
  int newHealth;
  
  // blue men lose one dice for every 4 damage that is done against them.
  // for example if the strength is 8 they will lose one defence dice
  if(creatureStrength % 4 == 2) {
    cout << "\n\n\tBlue men are down a man and a dice!" << endl;
    defendDieThree = 0;
  } else if(creatureStrength % 4 == 1) {
    cout << "\n\n\tBlue men are down two men and two dice!" << endl;
    defendDieTwo = 0;
    defendDieThree = 0;
  }

  if(a == 666) {
    newHealth = 0;
  } else if(totalDefendScore > a) {
    newHealth = tempStrength;
  } else {
    newHealth = tempStrength - (a - totalDefendScore);
    if(newHealth > tempStrength) {
      newHealth = tempStrength;
    }
  }

  setCreatureStrength(newHealth);

  return totalDefendScore;
}
