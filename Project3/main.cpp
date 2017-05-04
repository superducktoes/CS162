#include <iostream>
#include <time.h>
#include <cstdlib>

using std::endl;
using std::cout;
using std::cin;
using std::string;

class Creature {
protected:
  string creatureName;
  int creatureArmor;
  int creatureStrength;
public:
  Creature();
  Creature(string);
  virtual int attackRollDie() = 0;
  virtual int defendRollDie(int) = 0;
  string getCreatureName() { return creatureName; }
  int getCreatureArmor() { return creatureArmor; }
  int getCreatureStrength() { return creatureStrength; }
};

class Barbarian: public Creature {
public:
  Barbarian(string s) : Creature(s) {};
  int attackRollDie();
  int defendRollDie(int);
};

class Vampire: public Creature {
public:
  Vampire(string s) : Creature(s) {};
  int attackRollDie();
  int defendRollDie(int);
};

Creature::Creature() {
  creatureName = " ";
  creatureArmor = 0;
  creatureStrength = 0;
}

Creature::Creature(string name) {
  if(name == "barbarian") {
    this->creatureName = name;
    this->creatureArmor = 0;
    this->creatureStrength = 12;
  } else if(name == "vampire") {
    this->creatureName = name;
    this->creatureArmor = 1;
    this->creatureStrength = 12;
  } else if(name == "bluemen") {
    this->creatureName = name;
    this->creatureArmor = 3;
    this->creatureStrength = 12;
  } else if(name == "medusa") {
    this->creatureName = name;
    this->creatureArmor = 3;
    this->creatureStrength = 18;
  } else if(name == "harrypotter") {
    this->creatureName = name;
    this->creatureArmor = 0;
    // this should be able to stay as 10
    this->creatureStrength = 10;
  }
}

int Barbarian::attackRollDie() {
  int attackDieOne = 1 + rand() % 6;
  int attackDieTwo = 1 + rand() % 6;

  return (attackDieOne + attackDieTwo);
}

int Barbarian::defendRollDie(int a) {
  int defendDieOne = 1 + rand() % 6;
  int defendDieTwo = 1 + rand() % 6;
  int totalDefendScore = (a - (defendDieOne - defendDieTwo) - creatureArmor);

  // updates the barbarians strength based on the attack roll and what was determined above
  this->creatureStrength = this->creatureStrength - totalDefendScore;

  return totalDefendScore;
}

int main() {
  srand ( time(NULL) );
  Creature* playerOneCreature;
  Creature* playerTwoCreature;

  playerOneCreature = new Barbarian("barbarian");
  playerTwoCreature = new Barbarian("barbarian");
  cout << playerTwoCreature->getCreatureStrength() << endl;
  int pOneAttack = playerOneCreature->attackRollDie();
  cout << playerOneCreature->attackRollDie() << endl;
  cout << playerTwoCreature->defendRollDie(pOneAttack) << endl;
  cout << playerTwoCreature->getCreatureStrength() << endl;

  return 0;
}
