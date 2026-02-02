#include "RPN.hpp"
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : elements(other.elements) {}

RPN& RPN::operator=(const RPN& other) {
  if (this != &other)
    elements = other.elements;
  return (*this);
}

RPN::~RPN() {}

void print_stack(std::stack<int> stack) {
  std::cout << "STACK size: " << stack.size() << std::endl;

  while (!stack.empty()) {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << std::endl;
}

void RPN::calculate(const std::string& exp) {
  std::stringstream ss(exp);
  std::string token;
  int result;

  while (ss >> token) {
    if (token.size() != 1) {
      std::cerr << "Error" << std::endl;
      return;
    }
    if (isdigit(token[0])) {
      result = token[0] - 48;
      elements.push(token[0] - 48);
    } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' ||
               token[0] == '/') {
      if (elements.size() < 2) {
        std::cerr << "Error" << std::endl;
        return;
      }
      int y = elements.top();
      elements.pop();
      int x = elements.top();
      elements.pop();

      switch (token[0]) {
        case '+':
          result = x + y;
          break;
        case '-':
          result = x - y;
          break;
        case '*':
          result = x * y;
          break;
        case '/':
          if (y == 0) {
            std::cerr << "Error" << std::endl;
            return;
          }
          result = x / y;
          break;
      }
      elements.push(result);
    } else {
      std::cerr << "Error" << std::endl;
      return;
    }
  }
  if (elements.size() != 1) {
    std::cerr << "Error" << std::endl;
    return;
  }
  std::cout << result << std::endl;
}
