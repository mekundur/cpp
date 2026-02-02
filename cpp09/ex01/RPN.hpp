#pragma once

#include <list>
#include <stack>
#include <string>

class RPN {

 private:
  std::stack<int, std::list<int> > elements;

 public:
  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  ~RPN();

  void calculate(const std::string& exp);
};
