#include <iostream>

#include "creature.hpp"
#include "vampire.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;

//vampire attack/defend
int Vampire::attackRollDie() {
  int attackDieOne = 1 + rand() % 12;
  return attackDieOne;
}

int Vampire::defendRollDie(int a) {
  int defendDieOne = 1 + rand() % 6;
  int totalDefendScore = defendDieOne + this->creatureArmor;
  int tempStrength = this->creatureStrength;
  int newHealth;
  // generates a random number between 1 and 2
  // if it's a 1 the attack does nothing to our vampire
  int halfChance = 1 + rand() % 2;
  
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

  if(halfChance == 1) {
    newHealth = tempStrength;
    cout << "\nVampire uses charm and the attack does nothing!" << endl;
  }
  
  setCreatureStrength(newHealth);
  
  return totalDefendScore;
}
