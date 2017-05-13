#include "rock.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Rock::Rock() {
  strength = 1;
  type = 'r';
  objectName = "Rock";
}

Rock::Rock(int s) {
  strength = s;
  type = 'r';
  objectName = "Rock";
}

// takes the opponent as an argument and returns a string whether rock wins or loses
string Rock::fight(Tool* other) {
  char otherType = other->getType();
  int rockStrength = this->getStrength();
  string matchStatus;

  if(otherType == 's') {
    cout << "Fighting against scissors!" << endl;
    // since we're fighting scissors we need to double our strength
    rockStrength = rockStrength * 2;
    if(rockStrength > other->getStrength()) {
      matchStatus = "won";
    } else if(rockStrength < other->getStrength()) {
      matchStatus = "lost";
    } else {
      matchStatus = "tie";
    }
  } else if(otherType == 'p') {
    cout << "Fighting against paper!" << endl;
    // against paper we need to cut rock's strength in half
    rockStrength = (rockStrength / 2);

    if(rockStrength > other->getStrength()) {
      matchStatus = "won";
    } else if(rockStrength < other->getStrength()) {
      matchStatus = "lost";
    } else {
      matchStatus = "tie";
    }
  }

  return matchStatus;
}
