#ifndef MONSTERSTACK_HPP
#define MONSTERSTACK_HPP
#include "creature.hpp"

class MonsterStack {

protected:
  struct MonsterLosers {
    Creature* loserMonsterPointer;
    MonsterLosers* next;


    MonsterLosers(Creature* loserMonsterPointer1, MonsterLosers* next1 = NULL) {
      loserMonsterPointer = loserMonsterPointer1;
      next = next1;
    }
  };
    MonsterLosers* head;
public:
  MonsterStack();
  ~MonsterStack();
  void addToStack(Creature*);
  Creature* removeFromStack();

};
#endif
