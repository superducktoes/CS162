#include <iostream>

#include "creature.hpp"
#include "harrypotter.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;

// harry potter attack and defense
int HarryPotter::attackRollDie() {
  int attackDieOne = 1 + rand() % 6;
  int attackDieTwo = 1 + rand() % 6;
  int attackRollDie = (attackDieOne + attackDieTwo);

  return attackRollDie;
}

int HarryPotter::defendRollDie(int a) {
  int defendDieOne = 1 + rand() % 6;
  int defendDieTwo = 1 + rand() % 6;
  int totalDefendScore = (defendDieOne + defendDieTwo) + this->creatureArmor;
  int tempStrength = this->creatureStrength;
  int newHealth;
  
  if(a == 666) {
    regenerate = false;
    newHealth = 0;
  } else if(totalDefendScore > a) {
    newHealth = tempStrength;
  } else {
    newHealth = tempStrength - (a - totalDefendScore);
    if(newHealth > tempStrength) {
      newHealth = tempStrength;
    }
  }

  // one time condition that if harrypotter dies he regenerates with 20 strength
  if(newHealth <= 0 && regenerate == true) {
    regenerate = false;
    newHealth = 20;
    cout << "Wingardium Leviosa! Harry Potter cannot be stopped! He has regenerated with 20 strength!" << endl;
  }

  setCreatureStrength(newHealth);
  return totalDefendScore;
}
