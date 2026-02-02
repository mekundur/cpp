#include "PmergeMe.hpp"
#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _myVec(other._myVec), _myDeq(other._myDeq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    this->_myDeq = other._myDeq;
    this->_myVec = other._myVec;
  }
  return (*this);
}

PmergeMe::~PmergeMe() {}

// Getters
std::vector<int> PmergeMe::get_myVec() const {
  return (_myVec);
}

std::deque<int> PmergeMe::get_myDeq() const {
  return (_myDeq);
}

// Start of recursive sorting
void PmergeMe::sort() {

  //std::cout << "------------------------------------------" << std::endl;
  std::cout << "Before: ";
  printVec(_myVec);
  double vecStart = getCurrentTime();
  fordJohnson(_myVec, 1);
  double vecEnd = getCurrentTime();
  std::cout << "After : ";
  printVec(_myVec);
  //std::cout << "------------------------------------------" << std::endl;
  //std::cout << "_RESULT: ";
  //std::cout << "STEPS: " << vsteps << std::endl;

  //std::cout << "------------------------------------------" << std::endl;
  // printDeq(_myDeq);
  double deqStart = getCurrentTime();
  fordJohnson(_myDeq, 1);
  double deqEnd = getCurrentTime();
  // printDeq(_myDeq);
  //std::cout << "------------------------------------------" << std::endl;
  //std::cout << "_RESULT: ";
  //std::cout << "STEPS: " << dsteps << std::endl;

  std::cout << "Time to process a range of " << _myVec.size()
            << " elements with std::vector : " << (vecEnd - vecStart)
            << " us\n";

  std::cout << "Time to process a range of " << _myDeq.size()
            << " elements with std::deque : " << (deqEnd - deqStart) << " us\n";
}

// Input parsing and storing:
void PmergeMe::store_numbers(const std::string str) {
  for (size_t i = 0; i < str.size(); ++i) {
    if (!std::isdigit(str[i]))
      throw BadInputException();
  }
  if (str.size() > 10)
    throw BadInputException();
  if (str.size() == 10 && str > "2147483647")
    throw BadInputException();
  int value = std::atoi(str.c_str());
  if (value <= 0)
    throw BadInputException();

  _myVec.push_back(value);
  _myDeq.push_back(value);
}

// Exceptions
const char* PmergeMe::BadInputException::what() const throw() {
  return ("Error: Bad input");
}