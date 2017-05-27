#include <iostream>
#include "monsterstack.hpp"
#include "creature.hpp"

using std::cout;
using std::cin;
using std::endl;

// default constructor. set the head of the stack to NULL
MonsterStack::MonsterStack() {
  head = NULL;
}

MonsterStack::~MonsterStack() {
  MonsterLosers *deleteNode = head;
  bool carryOn = true;

  // loop through deleting nodes until we hit the -1
  do{
    if(deleteNode == NULL) {
      carryOn = false;
    }
    MonsterLosers* tempNode = deleteNode;
    deleteNode = deleteNode->next;
    delete tempNode;
  } while(carryOn == true);
}
// add the losing monster to the stack
void MonsterStack::addToStack(Creature* c) {
  head = new MonsterLosers(c, head);
}

//check to see if the stack is empty. if not return the node and then removeFromStack

Creature* MonsterStack::removeFromStack() {
  if(head == NULL) {
    return 0;
  } else {
    MonsterLosers *tempNode = head;
    Creature *tempCreature = head->loserMonsterPointer;
    head = tempNode->next;

    delete tempNode;
    return tempCreature;
  }
}
