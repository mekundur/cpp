#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

/** 
 * @brief max number of comparisons required to sort n elements by merge insertion
 * (Ford-Johnson algorithm)
 * according to Donald E.Kuth (1998): The Art of Computer Programming (Vol. 3): 186p
 */
long maxComparisonsFJ(int n) {
  long sum = 0;

  for (int i = 1; i <= n; i++) {
    double value = (3.0 / 4.0) * i;
    sum += static_cast<long>(ceil(log2(value)));
  }
  return sum;
}
/** 
 * @brief functions for checking if the last set of number sorted for real
 */
bool isSortedAscending(const std::vector<int>& nums) {
  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] < nums[i - 1] || nums[i - 1] == 0) {
      return false;
    }
  }
  return true;
}
bool isSortedAscending(const std::deque<int>& nums) {
  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] < nums[i - 1] || nums[i - 1] == 0) {
      return false;
    }
  }
  return true;
}

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

/** 
 * @brief // Entrypoint and output handling happens here
 */
void PmergeMe::sort() {

  _vecResult = _myVec;
  double vecStart = getCurrentTime();
  fordJohnson(_vecResult, 1);
  double vecEnd = getCurrentTime();

  _deqResult = _myDeq;
  double deqStart = getCurrentTime();
  fordJohnson(_deqResult, 1);
  double deqEnd = getCurrentTime();

  std::cout << "V_Before: ";
  printVec(_myVec);
  std::cout << "V_After : ";
  printVec(_vecResult);

  std::cout << "D_Before: ";
  printDeq(_myDeq);
  std::cout << "D_After : ";
  printDeq(_deqResult);

  isSortedAscending(_vecResult)
      ? std::cout << "V is SORTED in " << vsteps << " comparasions"
      : std::cout << "V is NOT_SORTED!!!";
  std::cout << std::endl;
  isSortedAscending(_deqResult)
      ? std::cout << "D is SORTED in " << dsteps << " comparasions"
      : std::cout << "D is NOT_SORTED!!!";
  std::cout << std::endl;

  std::cout << "F&J treshold:  " << maxComparisonsFJ(_myDeq.size())
            << std::endl;

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
