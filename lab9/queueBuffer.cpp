/*************************************************************************************
 *
 * Author: Nick Roy
 * Date: 6/4/17
 * Description: QueueBuffer adds random numbers to a queue based on the percentage
 * chance that is specified by the user.
 *
 *************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queueBuffer.hpp"

using std::cout;
using std::cin;
using std::endl;

int generateRandomInt(int b) {
  int randomNum = 1 + rand() % b;
  return randomNum;
}

// main part of the program. generates random numbers and takes user input to decide whether or not ints
// are added to the queue
void QueueBuffer::runQueueBuffer() {
  srand(time(NULL));
  for(int i=0; i<roundsToPlay; i++) {
    int intToQueue = generateRandomInt(10);
    int percentageAdd = generateRandomInt(100);
    int percentageRemove = generateRandomInt(100);
    
    cout << "Playing round " << (i+1) << " of " << roundsToPlay  << endl;
    queueLengthPrevious = myIntQueue.size();
    
    // check to see if we can add an int to the queue
    if(percentageAdd < percentage) {
      myIntQueue.push(intToQueue);
      cout << "added: " << intToQueue << endl;
    } else {
      cout << intToQueue << " not added to queue " << endl;
    }
    
    if(percentageRemove < percentage) {
      if(myIntQueue.empty()) {
	cout << "Queue is empty" << endl;
      } else {
	myIntQueue.pop();
      }
    } else {
      cout << "not removing from queue " << endl;
    }

    // calculate some stats
    queueLengthCurrent = myIntQueue.size();
    cout << "Average length of the queue: " << queueAverage << endl;
    queueAverage = (queueLengthPrevious * i + queueLengthCurrent) / (i + 1);

  }

  
}

// displays the queuebuffer. used at the end to verify the data in the queue
void QueueBuffer::displayQueueBuffer() {
  while(!myIntQueue.empty()) {
    cout << myIntQueue.front() << ", ";
    myIntQueue.pop();
  } 
}

