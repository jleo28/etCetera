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
      if (b == 0) {
        throw std::runtime_error("Division by zero error");
      }
      return a/b
    };
    //Trigonometric functions, basic logarithms, and power below:
    functions["sin"] = [](double a) {
      return std::sin(a);
    };
    functions["cos"] = [](double a) {
      return std::cos(a);
    };
    functions["tan"] = [](double a) {
      return std::tan(a);
    };
    functions["log"] = [](double a) {
      if(a <= 0) {
        throw std::runtime_error("Logarithm of non-positive value error")
      }
      return std::log(a);
    };
    functions["pow"] = [](double a, double b) {
      return std::pow(a, b);
    };
    //Common imperial/metric conversions below:
    unitConversions["in_to_cm"] = [](double in) {
      return in * 2.54;
    };
    unitConversions["cm_to_in"] = [](double cm) {
      return cm / 2.54;
    };
    unitConversions["ft_to_m"] = [](double ft) {
      return ft * 0.3048;
    };
    unit_Conversions["m_to_ft"] = [](double m) {
      return m / 0.3048;
    };
    unitConversions["lb_to_kg"] = [](double lb){
      return lb * 0.453592;
    };
    unitConversions["kg_to_lb"] = [](double kg) {
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

  //The calculator's main run function below:
  void run() {
    printIntro();
      while (true) {
        std::string input;
        std::cout << "Enter operation (or 'exit' to quit): ";
        std::cin >> input;
        if (input == "exit") {
          break;
        } 
        else if (input.size() == 1 && operations.find(input[0]) != operations.end()) {
          //Basic operations' processing
          char op = input[0];
          double a, b;
          std::cout << "Enter two operands: ";
          std::cin >> a >> b;
          try {
            double result = operations[op](a, b);
            std::cout << "Result: " << result << std::endl;
          } 
          catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
          }
        } 
        else if (functions.find(input) != functions.end()) {
          //Advanced functions' processing
          double a;
          std::cout << "Enter operand: ";
          std::cin >> a;
          try {
            double result = functions[input](a);
            std::cout << "Result: " << result << std::endl;
          } 
          catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
          }
        } 
        else if (input == "pow") {
          //Power functions' unique case (two operands)
          double a, b;
          std::cout << "Enter base and exponent: ";
          std::cin >> a >> b;
          try {
            double result = functions[input](a, b);
            std::cout << "Result: " << result << std::endl;
          } 
          catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
          }
        } 
        else if (unitConversions.find(input) != unitConversions.end()) {
          //Unit conversions' processing
          double value;
          std::cout << "Enter value to convert: ";
          std::cin >> value;
          try {
            double result = unitConversions[input](value);
            std::cout << "Converted value: " << result << std::endl;
          } 
          catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
          }
        } 
        else if (calculusOperations.find(input) != calculusOperations.end()) {
          //Calculus operations' processing
          if (input == "diff") {
            double x;
            std::cout << "Enter x for differentiation: ";
            std::cin >> x;
            try {
              //Example function for differentiation (sin function in this case)
              std::function<double(double)> func = [](double x) { return std::sin(x); };
              double result = calculusOperations[input](func, x);
              std::cout << "Result: " << result << std::endl;
            } 
            catch (const std::exception &e) {
              std::cerr << e.what() << std::endl;
            }
          } 
          else if (input == "int") {
            double a, b;
            std::cout << "Enter lower and upper limits for integration: ";
            std::cin >> a >> b;
            try {
              //Example function for integration (sin function in this case)
              std::function<double(double)> func = [](double x) { return std::sin(x); };
              double result = calculusOperations[input](func, a, b);
              std::cout << "Result: " << result << std::endl;
            } 
            catch (const std::exception &e) {
              std::cerr << e.what() << std::endl;
            }
          }  
        } 
        else {
          std::cerr << "Unknown operation!" << std::endl;
        }
    }
  }
} 
