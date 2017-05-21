/*****************************************************************
 *
 * Author: Nick Roy
 * Date: 5/21/2017
 * Description: queue node class. implements functions for adding to the queue
 * and showing the front node of the queue.
 *
 ****************************************************************/

#include <iostream>
#include "queuenode.hpp"

using std::cout;
using std::cin;
using std::endl;

//constructor for queue
Queue::Queue() {
  QueueNode* newNode = new QueueNode();
  //sets the new nodes pointers
  newNode->value = -1;
  newNode->next = newNode;
  newNode->previous = newNode;
  // sets the front and back to the new node created
  front = newNode;
  back = newNode;
}

// getfront gets the value of the first stored node.
// returns -1 if the queue is empty.
int Queue::getFront() {
  return front->value;
}

// removes the front node and then pushes back
void Queue::removeFront() {
  int tempVal = front->value;

  //for single item queue
  if(front->next == back) {
    front->value = -1;
  } else {
    // anything else falls here
    front->value = -1;
    back = front;
    front = front->next;
  }

}

//addback adds a node to the back of the queue using the int passed by the user
void Queue::addBack(int v) {
  QueueNode *nodeBack = back->next;
  QueueNode *addNode;
  // build a node after the last node and if it's empty set the value to v
  // from the user
  if(nodeBack->value == -1) {
    nodeBack->value = v;
  } else {
    // if not then we need to insert it between the last node and the node created
    // above
    addNode = new QueueNode;
    addNode->value = v;
    addNode->previous = back;
    addNode->next = nodeBack;

    // update all of our pointers
    back->next = addNode;
    nodeBack->previous = addNode;
    nodeBack = addNode;
  }
}

// destructor to free up our memory
Queue::~Queue() {
  QueueNode *deleteNode = front;
  bool carryOn = true;

  // loop through deleting nodes until we hit the -1
  do{
    if(deleteNode == back) {
      carryOn = false;
    }
    QueueNode* tempNode = deleteNode;
    deleteNode = deleteNode->next;
    delete tempNode;
  } while(carryOn == true);
}
