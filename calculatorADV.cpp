//Hi! As part of a self-paced course in tinkering with my C++ skills, I'll be attempting to write code for a Complex Calculator in C++.
//I'll be writing the base code here on Github, but I'll be running parallel tests on VSCode.
//The reason I'm doing this is just to get a better feel for continuous workflow on Github ^-^.

#include <iostream>
#include <cmath>
#include <map>
#incldue <functional>
#include <stdexcept>

//The main "Calc" class will perform basic arithmetic operations, functions, unit conversions, and (elementary) calculus.
class Calc {
public:
  //This constructor is used for basic arithmetic operations/ functions. and unit conversions
  Calculator() {
    //Basic arithmetic operations below:
    operations["+"] = [](double a, double b) {
      return a + b;
    }
    operations["-"] = [](double a, double b) {
      return a - b;
    }
    operations["*"] = [](double a, double b) {
      return a * b
    }
    operations["/"] = [](double a, double b) {
      if {b == 0} {
        throw std::runtime_error("Division by zero error");
      }
      return a/b
    };

  }
} 
