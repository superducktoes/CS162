#ifndef CREATURE_HPP
#define CREATURE_HPP

using std::string;

class Creature {
protected:
  string creatureName;
  string playerChoice;
  int creatureArmor;
  int creatureStrength;
public:
  Creature();
  Creature(string,string);
  virtual int attackRollDie() = 0;
  virtual int defendRollDie(int) = 0;
  string getCreatureName() { return creatureName; }
  string getCreaturePlayer() { return playerChoice; }
  int getCreatureArmor() { return creatureArmor; }
  int getCreatureStrength() { return creatureStrength; }
  void setCreatureStrength(int);
};
#endif
