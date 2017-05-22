#include <iostream>

#include "creature.hpp"
#include "barbarian.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;

// barbarian attack/defense
int Barbarian::attackRollDie() {
  int attackDieOne = 1 + rand() % 6;
  int attackDieTwo = 1 + rand() % 6;

  return (attackDieOne + attackDieTwo);
}

int Barbarian::defendRollDie(int a) {
  int defendDieOne = 1 + rand() % 6;
  int defendDieTwo = 1 + rand() % 6;
  int totalDefendScore = defendDieOne + defendDieTwo + this->creatureArmor;
  int tempStrength = this->creatureStrength;
  int newHealth;
  
  // theres a couple of things going on here. if we get 666 from medusa we'll set the health to 0
  // if the defender rolls greater than the attacker we'll keep their strength the same
  // other than that we calculate the new score to set the barbarian
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
