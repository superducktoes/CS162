#ifndef MONSTERSQUEUE_HPP
#define MONSTERSQUEUE_HPP
#include "creature.hpp"

class MonstersQueue {

protected:
  struct QueueNode {
    Creature* monsterPointer;
    QueueNode* next;
    QueueNode* previous;

    QueueNode(Creature* mP) {
      monsterPointer = mP;
      next = NULL;
      previous = NULL;
    }
  };

  // start and end of the list
  QueueNode* head;
  QueueNode* tail;
  QueueNode* node;
public:
  // constructor and destructor
  MonstersQueue();
  ~MonstersQueue();
  // remove the top item in the list
  Creature* getFront();
  // functions to add to and show the list
  void addToQueue(Creature*);
};
#endif
