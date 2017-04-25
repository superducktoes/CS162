/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/30/2017
  * Description: List class tracks the items created but can also remove them.
  * also has functions for comparison and returning the total of the groceries.
  *
  *****************************************************************************/
#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"
#include <string>
using std::string;

class List {
private:
  Item** listItem;
  int itemCount; // number of items in the cart
  int listMax; // max size of the array

public:
  List();
  bool operator==(string); // takes the name of the newly added object and compares to list of items
  void addItem(string,string,int,double);
  void removeItem(string);
  void displayList();
  void allocate();
  void printList();
  double returnGroceryTotal();

};
#endif
