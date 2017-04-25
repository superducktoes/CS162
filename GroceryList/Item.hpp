/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/30/2017
  * Description: Item class. Used for keeping track of the description of the
  * item, price, and the extended price(quantity * price).
  *
  *****************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
using std::string;

class Item {
private:
  string itemName;
  string unitType;
  int quantity;
  double price;
  double extendedPrice;

public:
  Item(string i, string u, int q, double p)
  : itemName(i), unitType(u), quantity(q), price(p)
  {
    extendedPrice = q*p;
  }
  string getItemName();
  string getItemUnitType();
  int getQuantity();
  double getPrice();
  double getExtendedPrice();
  void printItemInfo();
};
#endif
