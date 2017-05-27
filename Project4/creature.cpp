#include <iostream>

#include "creature.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;

Creature::Creature() {
  creatureName = " ";
  creatureArmor = 0;
  creatureStrength = 0;
}

Creature::Creature(string name, string player) {
  if(name == "barbarian") {
    this->creatureName = name;
    this->playerChoice = player;
    this->creatureArmor = 0;
    this->creatureStrength = 12;
  } else if(name == "vampire") {
    this->creatureName = name;
    this->playerChoice = player;
    this->creatureArmor = 1;
    this->creatureStrength = 12;
  } else if(name == "bluemen") {
    this->creatureName = name;
    this->playerChoice = player;
    this->creatureArmor = 3;
    this->creatureStrength = 12;
  } else if(name == "medusa") {
    this->creatureName = name;
    this->playerChoice = player;
    this->creatureArmor = 3;
    this->creatureStrength = 18;
  } else if(name == "harrypotter") {
    this->creatureName = name;
    this->playerChoice = player;
    this->creatureArmor = 0;
    // this should be able to stay as 10
    this->creatureStrength = 10;
  }
}


void Creature::setCreatureStrength(int s) {
  creatureStrength = s;
}
