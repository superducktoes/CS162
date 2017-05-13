#include "tool.hpp"

Tool::Tool() {}

Tool::Tool(int s) {
  strength = s;
}

void Tool::setType(char t) {
  type = t;
}

char Tool::getType() {
  return type;
}

void Tool::setStrength(int s) {
  strength = s;
}

int Tool::getStrength() {
  return strength;
}
