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
#include "menu.hpp"

using namespace std;

int displayMenu();

int main() {

  dLL *list = new dLL();
  int userChoice = 0;
  double userNumber;

  //variables for reading the file
  string filePath = "test_list_load.txt";
  ifstream inputFile("test_list_load.txt");
  string line;
  cout << "Options 7,8, and 9 are for extra credit" << endl;
  do {
    userChoice = displayMenu();
    switch(userChoice) {
    case 1:
      cout << "Number to add to head: " << endl;
      cin >> userNumber;
      list->addToHead(userNumber);
      break;
    case 2:
      cout << "Number to add to tail: " << endl;
      cin >> userNumber;
      list->addToTail(userNumber);
      break;
    case 3:
      list->deleteNodeHead();
      break;
    case 4:
      list->deleteNodeTail();
      break;
    case 5:
      list->displayNodesBackwards();
      break;
    case 6:
      list->displayNodesForward();
      break;
    case 7:
      list->displayHeadNode();
      break;
    case 8:
      list->displayTailNode();
      break;
    case 9:

      while(getline(inputFile,line)) {
	if(!line.length())
	  continue;
	istringstream iss(line);
	double number;
	iss >> number;
	list->addToHead(number);
      }
      cout << "Added numbers to list. " << endl;
      inputFile.close();
      break;
    case 10:
      userChoice = 10;
      break;
    }
  } while (userChoice != 10);

  return 0;
}

int displayMenu() {

  int userChoice;

  cout << "1. Add a new node to the head. " << endl;
  cout << "2. Add a new node to the tail. " << endl;
  cout << "3. Delete from head. " << endl;
  cout << "4. Delete from tail. " << endl;
  cout << "5. Traverse the list reversely. " << endl;
  cout << "6. Traverse the list forwards. " << endl;
  cout << "7. Show the head node. " << endl;
  cout << "8. Show the tail node. " << endl;
  cout << "9. Build list from file. " << endl;
  userChoice = checkNumber("10. Exit. ");
  cout << "\n\n";
  return userChoice;
}
