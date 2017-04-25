/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/30/2017
  * Description: Item class. Used for keeping track of the description of the
  * item, price, and the extended price(quantity * price).
  *
  *****************************************************************************/

#include "Item.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string Item::getItemName() {
  return itemName;
}
string Item::getItemUnitType() {
  return unitType;
}
int Item::getQuantity() {
  return quantity;
}
double Item::getPrice() {
  return price;
}

void Item::printItemInfo() {
  cout << " Item name: " << itemName << " Item Unit: " << unitType << " Quantity: " << quantity << " Price: " << price << endl;
}

double Item::getExtendedPrice() {
  return extendedPrice;
}
