#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
  // Test1
  std::cout << "Test1" << std::endl;
  try {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    // sp.printVect();
    std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
    std::cout << sp.longestSpan() << " = Longest" << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  // Test2
  std::cout << "Test2" << std::endl;
  try {
    Span sp = Span(5);

    for (int i = 0; i < 6; i++) {
      if (i % 2)
        sp.addNumber(i * 2);
      else
        sp.addNumber(i * 3);
    }
    // sp.printVect();
    std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
    std::cout << sp.longestSpan() << " = Longest" << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  // Test3
  std::cout << "Test3" << std::endl;
  try {
    Span sp = Span(5);

    sp.addNumber(1);
    // sp.printVect();
    std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
    std::cout << sp.longestSpan() << " = Longest" << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  // Test4
  std::cout << "Test4" << std::endl;
  try {
    Span sp = Span(20000);

    for (int i = 0; i < 20000; i++) {
      if (i % 2)
        sp.addNumber(i * 3);
      else
        sp.addNumber(i * 2);
    }
    // sp.printVect();
    std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
    std::cout << sp.longestSpan() << " = Longest" << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  // Test5
  std::cout << "Test5" << std::endl;
  try {
    Span sp = Span(100);

    sp.addNumber(1);
    sp.addNumber(2);

    std::vector<int> tmp;
    for (int i = 0; i < 98; i++) {
      if (i % 2)
        tmp.push_back(i * 2);
      else
        tmp.push_back(i * 3);
    }
    sp.addNumber(tmp.begin(), tmp.end());
    // sp.printVect();
    std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
    std::cout << sp.longestSpan() << " = Longest" << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  return 0;
}