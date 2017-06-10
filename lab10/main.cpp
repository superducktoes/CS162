#include <stdio.h>
#include <ctime>
#include <math.h>
#include <iostream>
#include <cstdlib>
// time from here: http://www.cplusplus.com/reference/ctime/clock/

#include "FibonacciNR.hpp"
#include "FibonacciR.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  clock_t t1;
  clock_t t2;
  int userNumber;
  if(argv[1] != 0) {
    cout << "using argument to calculate to the nth position." << endl;
    userNumber = atoi(argv[1]);
  } else {
  cout << "Calculate to the nth number: ";
  cin >> userNumber;
  }

  t1 = clock();
  FibonacciR fr(userNumber);
  fr.PrintFibonacci();
  t1 = clock() - t1;

  t2 = clock();
  FibonacciNR fnr(userNumber);
  fnr.PrintFibonacci();
  t2 = clock() - t2;

  printf ("It took me %d clicks to calculate using recursion (%f seconds).\n",t1,((float)t1)/CLOCKS_PER_SEC);
  printf ("It took me %d clicks to calculate using a loop (%f seconds).\n",t2,((float)t2)/CLOCKS_PER_SEC);
  cout << "finished. " << endl;
  return 0;
}
