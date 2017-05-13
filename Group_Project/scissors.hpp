#ifndef SCISSORS_HPP
#define SCISSORS_HPP
#include <string>

#include "tool.hpp"

class Scissors: public Tool {
public:
  Scissors();
  Scissors(int);
  string fight(Tool* other);
};
#endif
