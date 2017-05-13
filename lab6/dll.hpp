/*****************************************************************
 * 
 * Author: Nick Roy
 * Date: 5/14/2017
 * Description: Double linked list class. Implements functions to 
 * add to head and tail, display the list forwards and backwards, 
 * and allows for removing head and tail node
 *
 ****************************************************************/
 
#ifndef DLL_HPP
#define DLL_HPP

struct Node {
  double value;
  Node *next, *previous;
  Node(double v) {
    value = v;
    next = previous = NULL;
  }
};

class dLL {
  Node *headNode;
  Node *tailNode;

public:
  dLL() { headNode = NULL; tailNode = NULL; }
  ~dLL();
  void addToHead(double);
  void addToTail(double);
  void displayNodesForward();
  void displayNodesBackwards();
  void deleteNodeHead();
  void deleteNodeTail();
  void displayHeadNode();
  void displayTailNode();
};
#endif
