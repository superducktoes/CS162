#ifndef CREATURE_HPP
#define CREATURE_HPP

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
  void setCreatureStrength(int);
};
#endif
