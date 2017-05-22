#include <iostream>

#include "creature.hpp"
#include "medusa.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;

int Medusa::attackRollDie() {
  int attackDieOne = 1 + rand() % 6;
  int attackDieTwo = 1 + rand() % 6;
  int attackRollDie;

  // set to a number we can never get to to determine if glare is activated
  if((attackDieOne + attackDieTwo) == 12) {
    cout << "\n\n\tMedusa uses GLARE!" << endl;
    attackRollDie = 666;
  } else {
    attackRollDie = (attackDieOne + attackDieTwo);
  }

  return attackRollDie;
}

int Medusa::defendRollDie(int a) {
  int defendDieOne = 1 + rand() % 6;
  int totalDefendScore = defendDieOne + this->creatureArmor;
  int tempStrength = this->creatureStrength;
  int newHealth;

  if(a == 666) {
    cout << "Hit with glare!" << endl;
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
