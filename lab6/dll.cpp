/*****************************************************************
 *
 * Author: Nick Roy
 * Date: 5/14/2017
 * Description: Double linked list class. Implements functions to
 * add to head and tail, display the list forwards and backwards,
 * and allows for removing head and tail node
 *
 ****************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "dll.hpp"

using namespace std;

// destructor. removes all nodes
dLL::~dLL() {
  Node *currentNode = headNode;
  while(currentNode != NULL) {
    Node *garbage = currentNode;
    currentNode = currentNode->next;
    delete garbage;
  }
}

// shows the tail node. uses a temp node to assign the value to and check if it is not null

void dLL::displayTailNode() {
  Node *currentNode = tailNode;

  if(currentNode == NULL) {
    cout << "the list is empty" << endl;
  } else {
    cout << "Value of the tail node: ";
    cout << currentNode->value << endl;
  }
}

// shows the head node. temp node to check if null
void dLL::displayHeadNode() {
  Node *currentNode = headNode;

  if(currentNode == NULL) {
    cout << "the list is empty" << endl;
  } else {
    cout << "Value of the tail node: ";
    cout << currentNode->value << endl;
  }
}

// deletes the tail node and reassigns the last node not deleted.
// loops through to find the node
void dLL::deleteNodeTail() {
  Node *tempNode = headNode;
  if(tempNode == NULL) {
    cout << "the list is empty" << endl;
  } else {
  while(tempNode->next != tailNode) {
    tempNode = tempNode->next;
  }
  delete tailNode;
  tempNode->next = NULL;
  tailNode = tempNode;
  }
}

// removes the first node and then re-assigns
void dLL::deleteNodeHead() {
  Node *tempNode = headNode;
  if(tempNode == NULL) {
    cout << "the list is empty" << endl;
  } else {
    headNode = headNode->next;
    delete tempNode;
  }
}

// add a new node to the head and reassign the old node head. takes a double as an arg
void dLL::addToHead(double v) {

  Node *currentNode = new Node(v);

  //if the head node is null we know the list is empty
  //set the head and tail node
  if(headNode == NULL) {
    headNode = currentNode;
    tailNode = currentNode;
  } else {
    headNode->previous = currentNode;
    currentNode->next = headNode;
    headNode = currentNode;
  }
}

// adds a node to the tail, if empty. if there is a node there we update the existing tail node
void dLL::addToTail(double v) {

  Node *currentNode = new Node(v);

  if(tailNode == NULL) {
    headNode = currentNode;
    tailNode = currentNode;
  } else {
    tailNode->next = currentNode;
    currentNode->previous = tailNode;
    tailNode = currentNode;

  }
}

// loop through and display the list forwards
void dLL::displayNodesForward() {
  Node *currentNode = headNode;

  if(currentNode == NULL) {
    cout << "the list is empty" << endl;
  }

  while(currentNode != NULL) {
    cout << currentNode->value << "  ";
    currentNode = currentNode->next;
  }
  cout << "\n\n";
}

// start from the tail and display all the nodes
void dLL::displayNodesBackwards() {
  Node *currentNode = tailNode;

  if(currentNode == NULL) {
    cout << "the list is empty" << endl;
  }

  while(currentNode != NULL) {
    cout << currentNode->value << "  ";
    currentNode = currentNode->previous;
  }
  cout << "\n\n";
}
