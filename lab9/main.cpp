#include <iostream>
#include "queueBuffer.hpp"
#include "stack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  bool carryOn = true;
  
  do {
    int roundsToPlay = 0;
    int percentage = 0;
    int userChoice = 0;

    cout << "\nEnter your choice below to test the stack or queue. " << endl;
    cout << "1. Test the Queue with random numbers and chance " << endl;
    cout << "2. Test the Stack with a palindrome generator " << endl;
    cout << "0. To quit the program " << endl;
    cin >> userChoice;

    if(userChoice == 1) {
      cout << "How many rounds do you want to play? " << endl;
      cout << "Recommended to enter between 10 and 10,000 " << endl;
      cin >> roundsToPlay;
      
      cout << "Enter a number between 1 and 100 for the percentage chance the random number is added to the queue ";
      cin >> percentage;
      QueueBuffer qb(percentage,roundsToPlay);
      qb.runQueueBuffer();
      cout << "Final contents of the queue: ";
      qb.displayQueueBuffer();

    } else if (userChoice == 2) {
      cin.get();
      cin.clear();
      string userWord;  
      cout << "Enter a word to make a palindrome out of: ";
      getline(cin,userWord);
      palindromeStack(userWord);

    } else if(userChoice == 0) {
      carryOn = false;

    } else {
      cout << "Invalid option... " << endl;
    }
    
  } while (carryOn == true);

  return 0;
}
