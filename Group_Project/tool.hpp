#ifndef TOOL_HPP
#define TOOL_HPP
#include <string>

using std::string;

class Tool {
protected:
  int strength;
  char type;
  string objectName;
public:
  Tool();
  Tool(int);
  void setStrength(int);
  int getStrength();
  void setType(char);
  char getType();
  string getName() { return objectName; }
  virtual string fight(Tool* other) = 0;
};
#endif
