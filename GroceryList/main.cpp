#include <iostream>
#include <string>
#include <iomanip>

#include "Item.hpp"
#include "List.hpp"
#include "menu.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {

string itemName;
string itemUnit;
int itemQuantity;
double itemPrice;
List newList;
int userNumber = 0;
double groceryTotal = 0.0;

cout << "This is the grocery list program." << endl;
cout << "Let's start off simple and create an item: ";
// this is going to need formatting for displaying the money

bool carryOn = true;

do {
  cout << "Enter a number to modify the grocery list: " << endl;
  cout << "1. Add an item. " << endl;
  cout << "2. Remove an item. " << endl;
  cout << "3. Show current list. " << endl;
  userNumber = checkNumber("4. Quit and show total. " );

  switch (userNumber) {
    case 1:
      cin.clear();
      cin.ignore();
      cout << "\nEnter the name of the item: ";
      getline(cin,itemName);
      cout << "Enter the unit type for the item: ";
      getline(cin,itemUnit);
      cout << "How many of these items are you buying: ";
      cin >> itemQuantity;
      cout << "What is the price of the individual item: ";
      cin >> itemPrice;
      newList.addItem(itemName,itemUnit,itemQuantity,itemPrice);
      break;
    case 2:
      cout << "Enter the name of the item to remove: ";
      cin >> itemName;
      newList.removeItem(itemName);
      break;
    case 3:
      newList.printList();
      break;
    case 4:
      carryOn = false;
      break;
    default:
      cout << "Invalid entry. Please enter a number between 1 and 3" << endl;
      break;
  }
} while(carryOn == true);
  groceryTotal = newList.returnGroceryTotal();
  cout << "Here are all of the items on the list: " << endl;
  newList.printList();
  cout << std::fixed << std::showpoint << std::setprecision(2);
  cout << "Total cost of the groceries on the list is: $" << groceryTotal << endl;
  return 0;
}
