#ifndef PAPER_HPP
#define PAPER_HPP
#include <string>

#include "tool.hpp"

class Paper: public Tool {
public:
  Paper();
  Paper(int);
  string fight(Tool* other);
};
#endif
