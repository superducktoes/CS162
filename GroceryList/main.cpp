#include <iostream>
#include <string>
#include "Item.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {

string itemName;
string itemUnit;
int itemQuantity;
double itemPrice;

cout << "This is the grocery list program." << endl;
cout << "Let's start off simple and create an item: ";
// this is going to need formatting for displaying the money

cout << "Enter the name of the grocery item: ";
cin >> itemName;
cout << "What is the unit type of the item: ";
cin >> itemUnit;
cout << "How many items are you buying? ";
cin >> itemQuantity;
cout << "and finally, what is the price of the item? ";
cin >> itemPrice;

Item newItem(itemName,itemUnit,itemQuantity,itemPrice);

newItem.printItemInfo();
cout << "\n\n based on this you will pay per item: " << newItem.getExtendedPrice();

return 0;
}
