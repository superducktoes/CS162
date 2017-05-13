#include "paper.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Paper::Paper() {
  strength = 1;
  type = 'p';
  objectName = "Paper";
}

Paper::Paper(int s) {
  strength = s;
  type = 'p';
  objectName = "Paper";
}

string Paper::fight(Tool* other) {
  char otherType = other->getType();
  int paperStrength = this->getStrength();
  string matchStatus;

  if(otherType == 'r') {
    paperStrength = (paperStrength * 2);
    if(paperStrength > other->getStrength()) {
      matchStatus = "won";
    } else if(paperStrength < other->getStrength()) {
      matchStatus = "lost";
    } else {
      matchStatus = "tie";
    }
  } else if(otherType = 's') {
    paperStrength = (paperStrength/2);
    if(paperStrength > other->getStrength()) {
      matchStatus = "won";
    } else if(paperStrength < other->getStrength()) {
      matchStatus = "lost";
    } else {
      matchStatus = "tie";
    }
  }

  return matchStatus;
}
