/*****************************************************************
 *
 * Author: Nick Roy
 * Date: 5/21/2017
 * Description: queue node class. implements functions for adding to the queue
 * and showing the front node of the queue.
 *
 ****************************************************************/

#include <iostream>
#include "queuenode.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
  int userChoice = 0;
  bool carryOn = true;
  Queue myQueue;

  cout << "Enter a number to select an action. " << endl;

  do {
    cout << "1 to add a number to the queue. " << endl;
    cout << "2 to show the front node. " << endl;
    cout << "3 to remove the first node. " << endl;
    cout << "4 to display whats in the queue. " << endl;
    cout << "5 to exit. " << endl;

    cin >> userChoice;

    switch (userChoice) {
    case 1:
      {
	int numberToAdd;
	cout << "Enter the number to add: ";
	cin >> numberToAdd;
	myQueue.addBack(numberToAdd);
	cout << "Added " << numberToAdd << " to the queue. " << endl;
	cout << "\n\n";
	break;
      }
    case 2:
      {
	int numberQueue = myQueue.getFront();
	if(numberQueue != -1) {
	  cout << "The first node on the queue is: " << numberQueue << endl;
	} else {
	  cout << "The queue is empty. " << endl;
	}
	cout << "\n\n";
	break;
      }
    case 3:
      {
	cout << "Removing the first node from the queue. " << endl;
	myQueue.removeFront();
	cout << "\n\n";
	break;
      }
    case 4:
      {
	int temp = myQueue.getFront();
	
	if(temp == -1) {
	  cout << "The queue is empty " << endl;
	} else {
	  cout << "The values in the queue: " << endl;
	  do{
	    cout << temp;
	    myQueue.removeFront();
	    temp = myQueue.getFront();
	  } while(temp != -1);
	}
	cout << "\n\n";
	break;
      }
    case 5:
      {
	carryOn = false;
	break;
      }
    default:
      {
	cout << "Please enter a number between 1 and 5" << endl;
      }
    }
  } while(carryOn == true);
  
  
  return 0;
}
