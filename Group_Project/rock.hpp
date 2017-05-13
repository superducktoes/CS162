#ifndef ROCK_HPP
#define ROCK_HPP
#include <string>
#include "tool.hpp"

class Rock: public Tool {
public:
  Rock();
  Rock(int);
  string fight(Tool* other);
};
#endif
