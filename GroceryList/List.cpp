/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/30/2017
  * Description: List class tracks the items created but can also remove them.
  * also has functions for comparison and returning the total of the groceries.
  *
  *****************************************************************************/

#include "List.hpp"
#include "Item.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

List::List() {
  listItem = new Item*[4];
  itemCount = 0; // number of items in the list
  listMax = 4; // max length of the list
}

// overloaded operator
bool operator==(Item a, Item b) {
  return a.getItemName() == b.getItemName();
}

// still needs to check the size of the array
void List::addItem(string iN, string u, int q, double p) {
  bool addItem = true;

  // check to see if the list has reached it's limit and expand before adding
  // the object
  if(itemCount == listMax) {
      Item **tempItemList = new Item*[listMax + 1];
      // copies the list to a temp list that is N+1 in size and then swaps.
      tempItemList = listItem;
      listItem = tempItemList;
    }
  // needs to stay greater than 0 or else it segfaults
  if(itemCount > 0) {
    //loop through the list to see if the item is in there already
    for(int i = 0; i < itemCount; i++) {
      if(listItem[i]->getItemName() == iN) {
        cout << "that item exists in the list already" << endl;
        addItem = false;
      }
    }
    if(addItem == true) {
      //itemName, unitType, quantity, price
      listItem[itemCount] = new Item(iN, u, q, p);
      itemCount++;
      }
    } else  {
      // used for the first item added to the list
      //itemName, unitType, quantity, price
      listItem[itemCount] = new Item(iN, u, q, p);
      itemCount++;
    }
  }

void List::removeItem(string iN) {
  bool removeItem = false;

  if(itemCount > 0) {
  for(int j=0; j<itemCount;j++) {
    if(iN == listItem[j]->getItemName()) {
      cout << "Removing item: " << iN << endl;
      removeItem = true;
    }
  }
  if(removeItem == true) {
    // create a temp list to copy the items - the one looking for if found
    Item **tempItemList = new Item*[itemCount];
    // temp counter since the for loop counter will be off by 1 after finding an item
    int tempCounter = 0;

    for(int i = 0; i<itemCount; i++) {
      if(iN != listItem[i]->getItemName()) {
        tempItemList[tempCounter] = new Item(listItem[i]->getItemName(), listItem[i]->getItemUnitType(), listItem[i]->getQuantity(), listItem[i]->getPrice());
        tempCounter++;
      }
    }
    itemCount = itemCount - 1;
    listItem = tempItemList;
  }

} else {
    cout << "Cannot remove items from an empty list" << endl;
  }
}

double List::returnGroceryTotal() {
  double myGroceryTotal = 0.0;

  for(int i=0; i<itemCount; i++) {
      myGroceryTotal = myGroceryTotal + listItem[i]->getExtendedPrice();
  }
  return myGroceryTotal;
}

void List::printList() {
  for(int i = 0; i<itemCount; i++) {
    Item* printItem = listItem[i];
    printItem->printItemInfo();
  }
}
