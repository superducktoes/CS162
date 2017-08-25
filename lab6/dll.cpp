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
  Node *tempNode;
  if(tailNode == NULL) {
    cout << "the list is empty" << endl;
  } else {
    tempNode = tailNode->previous;
    delete tailNode;
    tailNode = tempNode;
    tailNode->next = NULL;

  }
}

// removes the first node and then re-assigns
void dLL::deleteNodeHead() {
  Node *tempNode;
  if(headNode == NULL) {
    cout << "the list is empty" << endl;
  } else {
    tempNode = headNode->next;
    delete headNode;

    headNode = tempNode;
    headNode->previous = NULL;

  }
}

// add a new node to the head and reassign the old node head. takes a double as an arg
void dLL::addToHead(double v) {
  Node *tempNode = new Node(v);
  Node *currentNode = headNode;

  if(currentNode == NULL) {
    headNode = tempNode;
    tailNode = tempNode;
  } else {
    currentNode->previous = tempNode;
    tempNode->next = currentNode;
    headNode = tempNode;
  }
}

// adds a node to the tail, if empty. if there is a node there we update the existing tail node
void dLL::addToTail(double v) {

  Node *tempNode = new Node(v);
  Node *currentNode = tailNode;

  // check to see if the list is empty
  if(tailNode == NULL) {
    headNode = tempNode;
    tailNode = tempNode;
  } else {
    tailNode->next = tempNode;
    tempNode->previous = currentNode;
    tailNode = tempNode;
  }
}

// loop through and display the list forwards
void dLL::displayNodesForward() {
  Node *tempNode = headNode;

  if(tempNode == NULL) {
    cout << "the list is empty" << endl;
  } else {
    while(tempNode != NULL) {
      cout << tempNode->value << endl;
      tempNode = tempNode->next;
    }
  }
}

// start from the tail and display all the nodes
void dLL::displayNodesBackwards() {
  Node *tempNode = tailNode;
  if(tempNode == NULL) {
    cout << "the list is empty" << endl;
  } else {
    while(tempNode != NULL) {
      cout << tempNode->value << endl;
      tempNode = tempNode->previous;
    }
  }
}
