#include <iostream>
#include "monstersqueue.hpp"
#include "creature.hpp"

using std::cout;
using std::cin;
using std::endl;

MonstersQueue::MonstersQueue() {
    head = NULL;
    tail = NULL;
}

Creature* MonstersQueue::getFront() {
  if(head == NULL) {
    cout << "The player's queue is empty. " << endl;
    return 0;
  } else {

    Creature *tempCreature = NULL;
    QueueNode *tempNode = head;

    tempCreature = tempNode->monsterPointer;
    head = head->next;
    if(head != NULL) {
      head->previous = NULL;
    }

    delete tempNode;
    return tempCreature;
  }
}

void MonstersQueue::addToQueue(Creature* c) {
  // if the queue does not have any monsters
  if(head == NULL) {
    head = new QueueNode(c);
    tail = head;
  } else {
    // assign new node and update pointers
    node = new QueueNode(c);
    node->next = NULL;
    tail->next = node;
    tail = node;
  }
}

MonstersQueue::~MonstersQueue() {
  QueueNode *deleteNode = head;
  bool carryOn = true;

  do {
    if(deleteNode == tail) {
      carryOn = false;
    }
    QueueNode* tempNode = deleteNode;
    deleteNode = deleteNode->next;
    delete tempNode;
  } while(carryOn == true);
}
