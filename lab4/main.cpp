/*******************************************************************************
 *
 * Author: Nick Roy
 * Date: 4/30/2017
 * Description: University system made up of three classes.
 * Building class stores information about the buildings
 * University class stores all buildings and students/instructors.
 *
 *****************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "menu.hpp"
#include "Person.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cin;


/*******************************************************************************
* Building class. Takes the name, size, and address in the constructors
*
* printBuildingInformation prints out information about any building objects
*******************************************************************************/

class Building {
  private:
    string buildingName;
  double buildingSize;
  string buildingAddress;
  public:
    Building(string bN, double bS, string bA)
    : buildingName(bN), buildingSize(bS), buildingAddress(bA)
    {
    }

  void printBuildingInformation() {
    cout << "\nBuilding Name: " << buildingName << "\nBuilding Address: " << buildingAddress << "\nBuilding Size: " << buildingSize << endl;
  }
};

/*******************************************************************************
* University class.
* Constructor doesn't take any arguments.
*
* addBuildingToVector and addPersonToVector takes the object and adds to the
* vector.
* print functions loop through the vectors and prints out everything
*******************************************************************************/

class University {
  private:
  vector <Building> buildingVector;
  vector <Person*> personVector;
  public:
    void printUniversityName() {
      cout << "Oregon State University" << endl;
    }
  void addBuildingToVector(Building b) {
    buildingVector.push_back(b);
  }
  void printBuildingVector();
  void addPersonToVector(Person* p) {
    personVector.push_back(p);
  }
  void printPersonVector();
};

void University::printBuildingVector() {
  cout << "Number of buildings on campus: " << buildingVector.size() << endl;
  for (int i = 0; i < buildingVector.size(); i++) {
    buildingVector[i].printBuildingInformation();
  }
}

void University::printPersonVector() {
  cout << "Number of students: " << personVector.size() << endl;
  for (int j = 0; j < personVector.size(); j++) {
    personVector[j] -> printPersonInformation();
  }
}

// prompts the user for a student or instructor and runs the appropriate do_work
// function for a Person
void handleDoWork() {
  char userLetter;
  bool carryOn = true;
  string personName;
  int age;
  double gpaRating; // used whether a student or instructor is created
  int hoursWorked;

  while(carryOn == true) {
    cout << ": ";
    cin >> userLetter;
    if(userLetter == 's' || userLetter == 'S') {
      Student s;
      Person* ptrStudent;
      cin.clear();
      cin.ignore();
      cout << "Enter the name of the student: ";
      getline(cin,personName);
      age = checkNumber("Enter the age of the student: ");
      gpaRating = checkNumberRange("Enter the GPA of the student: ", 0.0,4.0);
      hoursWorked = checkNumber("Enter the number of hours worked: ");
      s.setName(personName);
      s.setAge(age);
      s.setGpa(gpaRating);
      ptrStudent = &s;
      ptrStudent->do_work(hoursWorked);
      carryOn = false;
    } else if(userLetter == 'i' || userLetter == 'I') {
      Instructor i;
      Person* ptrInstructor;
      carryOn = false;
      cin.clear();
      cin.ignore();
      cout << "Enter the name of the instructor: ";
      getline(cin,personName);
      age = checkNumber("Enter the age of the instructor: ");
      gpaRating = checkNumberRange("What is the instructors rating: ",0.0,5.0);
      hoursWorked = checkNumber("Enter the number of hours worked: ");
      i.setName(personName);
      i.setAge(age);
      i.setRating(gpaRating);
      ptrInstructor = &i;
      ptrInstructor->do_work(hoursWorked);
      carryOn = false;
    } else {
      cout << "Please enter either S or I. " << endl;
    }
  }
}

int main() {
  // variables for the menu below
  bool carryOn = true;
  int userInput;

  // instantiate all of our necessary constructors
  Student s;
  Instructor i;
  Building b1("AS Adair Barn #1-Soap CR", 1652, "28120 BEEF BARN RD CORVALLIS OR 97330");
  Building b2("Filtering Plant (Langton)", 1741, "2350 SW JEFFERSON WAY CORVALLIS OR 97330");
  University u;
  Person * ptrStudent;
  Person * ptrInstructor;

  // set the instructor and the student
  s.setName("Nick");
  s.setAge(27);
  s.setGpa(3.5);
  i.setName("Ellen");
  i.setAge(27);
  i.setRating(10);

  // this is where the magic happens
  ptrStudent = &s;
  ptrInstructor = &i;

  // add our building to the university vector
  u.addBuildingToVector(b1);
  u.addBuildingToVector(b2);

  // add our person to the university vector
  u.addPersonToVector(ptrStudent);
  u.addPersonToVector(ptrInstructor);

  while (carryOn == true) {
    u.printUniversityName();
    cout << "University System Management Tool" << endl;
    cout << "1. Print the information about the buildings." << endl;
    cout << "2. Print information about everyone at the university." << endl;
    cout << "3. Choose a person to do work." << endl;
    userInput = checkNumber("4. Exit the program. ");

    switch (userInput) {
    case 1:
      u.printBuildingVector();
      break;
    case 2:
      u.printPersonVector();
      break;
    case 3:
      cout << "Do you want to have a student or instructor do work? ( S or I )" << endl;
      handleDoWork();
      break;
    case 4:
      carryOn = false;
      break;
    default:
      cout << "Please enter an option between 1 and 4." << endl;
    }
  }
  return 0;
}
