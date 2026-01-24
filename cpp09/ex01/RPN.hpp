#pragma once

#include <stack>
#include <string>

class RPN {

 private:
  std::stack<int> elements;

 public:
  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  ~RPN();

  void calculate(const std::string& exp);
};