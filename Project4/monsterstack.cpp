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
  cout << "destructor called" << endl;
}
// add the losing monster to the stack
void MonsterStack::addToStack(Creature* c) {
  head = new MonsterLosers(c, head);
}

//check to see if the stack is empty. if not return the node and then removeFromStack

Creature* MonsterStack::removeFromStack() {
  if(head == NULL) {
    cout << "the stack is empty";
    return 0;
  } else {
    MonsterLosers *tempNode = head;
    Creature *tempCreature = head->loserMonsterPointer;
    head = tempNode->next;

    delete tempNode;
    return tempCreature;
  }
}
