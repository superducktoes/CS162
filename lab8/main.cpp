/*******************************************************************************
 *
 * Author: Nick Roy
 * Date: 5/28/2017
 * Description: Lab has three files created locally and first prompts the user
 * which file they want to work with. After choosing the file, they are then
 * prompted to search the file using a linear search, sort the file using bubble
 * sort, or search a file using a binary search.
 *
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "menu.hpp"

using namespace std;

void linearSearch(vector<int>&);
void bubbleSort(vector<int>&,int);
void binarySearch(vector<int>&, int);

int main() {

  bool carryOn = true;
  bool displayOption = false;

  do {
    vector<int> numbersFromFile;
    string line;
    string filePath;
    int userChoice;

    cout << "\n\nPick the file that you want to load: " << endl;
    cout << "1. 0 at the start " << endl;
    cout << "2. 0 in the middle " << endl;
    cout << "3. 0 at the end " << endl;
    cout << "4. No 0 in the file " << endl;
    if(displayOption) {
      cout << "5. File created from bubble sort " << endl;
    }
    cout << "Enter 0 to exit " << endl;
    userChoice = checkNumber(" ");

    if(userChoice == 1) {
      filePath = "numbers_two";
    } else if(userChoice == 2) {
      filePath = "numbers_three";
    } else if(userChoice == 3) {
      filePath = "numbers_four";
    } else if(userChoice == 4) {
      filePath = "numbers_one";
    } else if(userChoice == 5) {
      filePath = "bubble_sort";
    } else if(userChoice == 0) {
      carryOn = false;
      break;
    } else {
      cout << "Invalid selection. Using file with no 0 " << endl;
      filePath = "numbers_one";
    }

    cout << "Contents of file: " << endl;
    // lets load the file into a vector
    ifstream inputFile(filePath);
    while(getline(inputFile,line)) {
      if(!line.length())
	continue;
      istringstream iss(line);
      int number;
      iss >> number;
      cout << number << "  ";
      numbersFromFile.push_back(number);
    }
    inputFile.close();

    userChoice = 0;

    cout << "\n\nDo you want to search or sort the numbers in the file: " << endl;
    cout << "1. Linear search for a number " << endl;
    cout << "2. Bubble Sort the numbers in the file " << endl;
    cout << "3. Binary search for a number " << endl;
    cout << "Enter 0 to exit " << endl;
    userChoice = checkNumber(" ");

    if(userChoice == 1) {
      linearSearch(numbersFromFile);
    } else if(userChoice == 2) {
      bubbleSort(numbersFromFile,numbersFromFile.size());
      displayOption = true;
    } else if(userChoice == 3) {
      binarySearch(numbersFromFile,numbersFromFile.size());
    } else if(userChoice == 0) {
      carryOn = false;
    } else {
      cout << "Invalid selection. Using linear search " << endl;
      linearSearch(numbersFromFile);
    }

  } while(carryOn == true);


  return 0;
}

// binary search. needs to be already sorted
void binarySearch(vector<int>& numbers, int size) {
  int start = 0;
  int valueToSearch;
  bool numberFound = false;

  //cout << "What number do you want to search for? ";
  //cin >> valueToSearch;
  valueToSearch = checkNumber("What number do you want to search for? ");

  while(start <= size && numberFound == false) {
    int middle = (start+size)/2;
    if(numbers[middle] == valueToSearch) {
      cout << valueToSearch << " found at position " << middle;
      numberFound = true;
    } else if(numbers[middle] > valueToSearch) {
      size = middle - 1;
    } else {
      start = middle + 1;
    }
  }

  if(numberFound == false) {
    cout << "Number not found or the numbers in the file are not in order" << endl;
  }
}


// from slide 5 on the sort-bubble.pdf set of slides
void bubbleSort(vector<int>& numbers, int size) {
  for(int i=(size-1); i>=0; i--) {
    for(int j=1; j<=i; j++) {
      if(numbers[j-1]>numbers[j]) {
	int temp = numbers[j-1];
	numbers[j-1] = numbers[j];
	numbers[j] = temp;
      }
    }
  }

  cout << "The sorted result is:  " << endl;

  ofstream myFile("bubble_sort");
  if(myFile.is_open()) {
    for(int k=0; k<numbers.size(); k++) {
      myFile << k << "\n";
      cout << k << "  ";
    }
  }
  myFile.close();
  cout << "\nWrote the sorted results to bubble_sort " << endl;
}

// from slide 6 in searching.pdf set of slides
void linearSearch(vector<int>& numbers) {
  bool zeroFound = false;
  int numberToSearch;

  //cout << "What number do you want to search for? ";
  //cin >> numberToSearch;
  numberToSearch = checkNumber("What number do you want to search for? ");
  for(int i=0; i<numbers.size();i++) {
    if(numbers[i] == numberToSearch) {
      cout << numberToSearch << " found at position " << (i+1) << endl;
      zeroFound = true;
    }
  }

  if(zeroFound == false) {
    cout << numberToSearch << "  not found in file. " << endl;
  }

}
