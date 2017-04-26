/*******************************************************************************
  *
  * Author: Nick Roy
  * Date: 4/30/2017
  * Description: University system made up of three classes. Student and Instructor
  * inherit from person. Building class stores information about the buildings
  * University class stores all buildings and students/instructors.
  *
  *****************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cin;

class Person {
protected:
  string name = " ";
  int age = 0;
public:
void setName(string n) {
  name = n;
}
void setAge(int a) {
  age = a;
}

virtual void do_work(int){}
virtual void printPersonInformation(){}
};

// inherits from Person
class Student:public Person {
private:
  double gpa=0.0;
public:
  void setGpa(double d) { gpa = d; }
  double getGpa() { return gpa; }
  void do_work(int h) {
    cout << name << " did " << h << " hours of homework!" << endl;
  }
  void printPersonInformation() {
    cout << "Student Name: " << name << "\nAge: " << age << "\nGPA: " << gpa << endl;
  }
};

// inherits from Person
class Instructor: public Person {
private:
  int rating = 0;
public:
  void setRating(int r) { rating = r; }
  int getRating() { return rating; }
  void do_work(int h) {
    cout << name << " graded papers for " << h << " hours." << endl;
  }
  void printPersonInformation() {
    cout << "Student Name: " << name << "\nAge: " << age << "\nRating: " << rating << endl;
  }
};
// default constructor takes all of the necesary information
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

// University has functions for adding to the vectors storing buildings and people
class University {
private:
  string universityName = "Oregon State University";
  vector<Building> buildingVector;
  vector<Person*> personVector;
public:
  void printUniversityName() { cout << universityName << endl; }
  void addBuildingToVector(Building b) { buildingVector.push_back(b); }
  void printBuildingVector();
  void addPersonToVector(Person* p) { personVector.push_back(p); }
  void printPersonVector();
};

void University::printBuildingVector() {
  cout << "Number of buildings on campus: " << buildingVector.size() << endl;
  for(int i=0; i<buildingVector.size(); i++) {
    buildingVector[i].printBuildingInformation();
  }
}

void University::printPersonVector() {
  cout << "Number of students: " << personVector.size() << endl;
  for(int j=0; j<personVector.size(); j++) {
    personVector[j]->printPersonInformation();
  }
}

int main() {
  // variables for the menu below
  bool carryOn = true;
  int userInput;

  // instantiate all of our necessary constructors
  Student s;
  Instructor i;
  Building b1("AS Adair Barn #1-Soap CR", 1652, "28120 BEEF BARN RD
CORVALLIS, OR 97330");
  Building b2("Filtering Plant (Langton)", 1741, "2350 SW JEFFERSON WAY
CORVALLIS, OR 97330")
  University u;
  Person* ptrStudent;
  Person* ptrInstructor;

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
  ptrStudent->do_work(5);
  ptrInstructor->do_work(5);

  // add our building to the university vector
  u.addBuildingToVector(b1);
  u.addBuildingToVector(b2);

  // add our person to the university vector
  u.addPersonToVector(ptrStudent);
  u.addPersonToVector(ptrInstructor);

  while(carryOn == true) {
    cout << "1. Print the information about the buildings." << endl;
    cout << "2. Print information about everyone at the university." << endl;
    cout << "3. Choose a person to do work." << endl;
    cout << "4. Exit the program. " << endl;
    cout << endl;
    cin >> userInput;

    switch (userInput) {
      case 1:
        u.printBuildingVector();
        break;
      case 2:
        u.printPersonVector();
        break;
      case 3:
        cout << "whatever for right now" << endl;
        break;
      case 4:
        carryOn = false;
        break;
      default:
        cout << "please enter an option between 1 and 4." << endl;
    }
  }
  return 0;
}
