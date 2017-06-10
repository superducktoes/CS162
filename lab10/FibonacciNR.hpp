/*
* FibonacciR.h
*
*  Created on: Sep 10, 2010
*      Author: julian
*/

#ifndef FIBONACCINR_HPP_
#define FIBONACCINR_HPP_

// source from here: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

class FibonacciNR {
  public:
     FibonacciNR(const int &n);
     virtual ~FibonacciNR();
     void PrintFibonacci();
  private:
     FibonacciNR();
     int Fibonacci(const int &n);
     const int* n_;
  };

#endif
