#include <iostream>

using std::cout;
using std::endl;

/*******************************************************************************
* Person class.
* Student and Instructor are dependant on Person.
* Student and instructor print appropirate information when called.
*******************************************************************************/

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

  virtual void do_work(int) {}
  virtual void printPersonInformation() {}
};

// inherits from Person
class Student: public Person {
  private: double gpa = 0.0;
  public: void setGpa(double d) {
    gpa = d;
  }
  double getGpa() {
    return gpa;
  }
  void do_work(int h) {
    cout << name << " did " << h << " hours of homework!" << endl;
  }
  void printPersonInformation() {
    cout << "Student Name: " << name << "\nAge: " << age << "\nGPA: " << gpa << endl;
  }
};

// inherits from Person
class Instructor: public Person {
  private: int rating = 0;
  public: void setRating(int r) {
    rating = r;
  }
  int getRating() {
    return rating;
  }
  void do_work(int h) {
    cout << name << " graded papers for " << h << " hours." << endl;
  }
  void printPersonInformation() {
    cout << "Student Name: " << name << "\nAge: " << age << "\nRating: " << rating << endl;
  }
};
