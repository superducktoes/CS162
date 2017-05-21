/*****************************************************************
 *
 * Author: Nick Roy
 * Date: 5/21/2017
 * Description: queue node class. implements functions for adding to the queue
 * and showing the front node of the queue.
 *
 ****************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

class Queue {
protected:
  struct QueueNode {
    int value;
    QueueNode *next;
    QueueNode *previous;
  };
  QueueNode *front;
  QueueNode *back;
public:
  Queue();
  ~Queue();
  void addBack(int);
  int getFront();
  void removeFront();
};
#endif
