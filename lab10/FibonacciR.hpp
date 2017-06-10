 /*
 * FibonacciR.h
 *
 *  Created on: Sep 10, 2010
 *      Author: julian
 */

 // source from here: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 
#ifndef FIBONACCIR_HPP_
#define FIBONACCIR_HPP_

  class FibonacciR {
  public:
     FibonacciR(const int &n);
     virtual ~FibonacciR();
     void PrintFibonacci();
  private:
     FibonacciR();
     int Fibonacci(const int &n);
     const int *n_;
  };

#endif /* FIBONACCIR_H_ */
