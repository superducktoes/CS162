#include <iostream>
#include <fstream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

int main() {
  string line;
  int numbers[11];

  ifstream myfile("numbers_two");
  if(myfile.is_open()) {
    while(!myfile.eof()) {
      getline(myfile,line);
      cout << line << endl;
      numbers[counter] = line;
      counter++;
    }
    myfile.close();
  }


  return 0;
}
