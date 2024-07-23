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
    //Trigonometric functions, basic logarithms, and power below:
    functions["sin"] = [](double a){
      return std::sin(a);
    };
    functions["cos"] = [](double a){
      return std::cos(a);
    };
    functions["tan"] = [](double a){
      return std::tan(a);
    };
    functions["log"] = [](double a){
      if(a <= 0){
        throw std::runtime_error("Logarithm of non-positive value error")
      }
      return std::log(a);
    };
    functions["pow"] = [](double a, double b){
      return std::pow(a, b);
    };
    //Common imperial/metric conversions below:
    unitConversions["in_to_cm"] = [](double in){
      return in * 2.54;
    };
    unitConversions["cm_to_in"] = [](double cm){
      return cm / 2.54;
    };
    unitConversions["ft_to_m"] = [](double ft){
      return ft * 0.3048;
    };
    unit_Conversions["m_to_ft"] = [](double m){
      return m / 0.3048;
    };
    unitConversions["lb_to_kg"] = [](double lb){
      return lb * 0.453592;
    };
    unitConversions["kg_to_lb"] = [](double kg){
      return kg / 0.453592;
    };
    //Simple calculus operations below:
    calculusOperations["diff"] = [this](std::function<double(double)> f, double x) {
      return this->differentiate(f, x);
    };
    calculusOperations["int"] = [this](std::function<double(double)> f, double a, double b) {
      return this->integrate(f, a, b);
    };
  }
} 
