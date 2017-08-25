#include <iostream>
#include <string>

using namespace std;

int factorial(int);
int bunnyEarsF(int);
int fibonacciF(int);
int triangleF(int);
int powerN(int,int);
int xCount(string, int *);
int changeXY(string,string *);

int main() {

  int total;
  total = factorial(3);
  cout << "Factorial: " << total << endl;;

  int bunnyEars;
  bunnyEars= bunnyEarsF(10);
  cout << "bunny ears: " << bunnyEars << endl;

  int fibonacci;
  fibonacci = fibonacciF(8);
  cout << "fibonacci: " << fibonacci << endl;

  int triangle;
  triangle = triangleF(4);
  cout << "triangle: " << triangle << endl;

  int power;
  power = powerN(10,5);
  cout << "power is: " << power << endl;

  string testString = "xhxoxixxhixhix";
  int xCounter = 0;
  xCount(testString,&xCounter);
  cout << "Checking the string " << testString << " for x's " << endl;
  cout << "X count is " << xCounter << endl;

  testString = "xhixhixxhixhix";
  string newString;
  changeXY(testString, &newString);
  cout << "the original string is " << testString << endl;
  cout << "and changing the x's with y's is " << newString << endl;

  return 0;
}

int changeXY(string s, string *pS) {
  
  int stringLength = s.length();
  
  if(stringLength == 0) {
    return 0;
  } else if(stringLength == 1) {
    if(s.at(0) == 'x') {
      *pS = *pS + 'y';
    }
    
    return 1;

  } else if(stringLength > 1) {
    
    if(s.at(0) == 'x') {
      *pS = *pS + 'y';
    } else {
      *pS = *pS + s.at(0);
    }
    
    s.erase(s.begin());
    changeXY(s,pS);
  }

}

// takes a string and a pointer as arguments
// checks the first char of the string and adds one to the pointer if its an x
// removes the first char and passes in again.
int xCount(string s, int *xCounter) {
  
  int stringLength = s.length();
  
  if(stringLength == 0) {
    return 0;
  } else if(stringLength == 1) {
    if(s.at(0) == 'x') {
      *xCounter = *xCounter + 1;
    }
    return 0;
  } else if(stringLength > 1) {
    
    if(s.at(0) == 'x') {
      *xCounter = *xCounter + 1;
    }
    
    s.erase(s.begin());
    xCount(s,xCounter);
  }
}

int powerN(int a, int b) {
  
  if( b == 0 ) {
    return 0;
  } else if( b == 1 ) {
    return a;
  } else if( b >= 2 ) {
    return 10 * powerN(a,(b-1));
  }
}

int triangleF(int a) {

  if(a == 0) {
    return 0;
  } else if(a == 1) {
    return 1;
  } else {
    return a + triangleF(a-1);
  }

}

int fibonacciF(int a) {
  
  if(a == 0) {
    return 0;
  } else if( a == 1) {
    return 1;
  } else {
    return fibonacciF(a-1) + fibonacciF(a-2);
  }
}
  

int bunnyEarsF(int a) {
  if(a == 0) {
    return 0;
  } else if ( a == 1) {
    return 2;
  } else {
    return 2 + bunnyEarsF(a-1);
  }
}

int factorial(int a) {
  
  if (a > 2) {
    return a * factorial(a-1);
  } else if ( a == 1 || a == 2) {
    return a;
  } else {
    return 0;
  }
}
