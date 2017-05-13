#include "scissors.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Scissors::Scissors() {
  strength = 1;
  type = 's';
  objectName = "Scissors";
}

Scissors::Scissors(int s) {
  strength = s;
  type = 's';
  objectName = "Scissors";
  
}

string Scissors::fight(Tool* other) {
  char otherType = other->getType();
  int scissorsStrength = this->getStrength();
  string matchStatus;

  if(otherType == 'r') {
    // rocks strength is doubled against scissors
    int rockStrength = other->getStrength();
    rockStrength = rockStrength * 2;

    cout << "Fighting against Rock!" << endl;

    if(scissorsStrength > rockStrength) {
      matchStatus = "won";
    } else if(scissorsStrength < rockStrength) {
      matchStatus = "lost";
    } else {
      matchStatus = "tie";
    }
  } else if(otherType == 'p') {
    // since scissors has the advantage against paper
    scissorsStrength = (scissorsStrength * 2);

    cout << "Fighting against Paper!" << endl;
    if(scissorsStrength > other->getStrength()) {
      matchStatus = "won";
    } else if(scissorsStrength < other->getStrength()) {
      matchStatus = "lost";
    } else {
      matchStatus = "tie";
    }
  }

  return matchStatus;
}
