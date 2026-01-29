#include "PmergeMe.hpp"
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _myVect(other._myVect), _myList(other._myList) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    this->_myList = other._myList;
    this->_myVect = other._myVect;
  }
  return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::store_numbers(std::string str) {
  std::stringstream ss(str);
  int n;
  while (ss >> n) {
    if (ss.fail())
      throw(BadInputException());
    _myVect.push_back(n);
    _myList.push_back(n);
  }
  _n = _myVect.size();
  printVect(_myVect);
  printList(_myList);
  generateJacobs();
  printVect(_jacobs);
}

void PmergeMe::generateJacobs() {
  _jacobs.push_back(0);
  _jacobs.push_back(1);
  for (int i = _jacobs.size(); _jacobs.back() < _n;) {
    _jacobs.push_back(_jacobs[i - 2] * 2 + _jacobs[i - 1]);
    i = _jacobs.size();
  }
}

const char* PmergeMe::BadInputException::what() const throw() {
  return ("Error: Bad input");
}

void insertVector(std::vector<int>& sorted, int value) {
  std::vector<int>::iterator it = sorted.begin();
  while (it != sorted.end() && *it < value)
    ++it;
  sorted.insert(it, value);
}
//////////////////////
void PmergeMe::fordJohnson(std::vector<int>& v, int i) {
  if (v.size() < 2)
    return;
  int leftover = 0;
  std::vector<int> large, small;
  for (std::vector<int>::iterator it = v.begin(); it != v.end();) {
    int a, b;
    a = *(it++);
    if (it != v.end()) {
      b = *(it++);
      large.push_back(a < b ? b : a);
      small.push_back(a < b ? a : b);
      //   if (a < b)
      //     std::swap(a, b);
    } else
      leftover = a;
  }
  std::cout << "RECURSION: ---------------------------------/" << std::setw(2)
            << i << std::endl;
  std::cout << "myVect: ";
  printVect(v);
  std::cout << "_large: ";
  printVect(large);
  std::cout << "_small: ";
  printVect(small);
  if (leftover)
    std::cout << "leftov: " << leftover << std::endl;

  fordJohnson(large, i + 1);

  std::cout << "RECURSION: ---------------------------------/" << std::setw(2)
            << -i << std::endl;
  std::cout << "_large: ";
  printVect(large);
  std::cout << "_small: ";
  printVect(small);
  // insertVector(large, small[]);
  //   _myVect = large;
  if (leftover)
    insertVector(large, leftover);
  std::cout << "myVect: ";
  printVect(v);
}
//////////////////////////////////
void PmergeMe::sort() {

  std::cout << "------------------------------------------" << std::endl;
  fordJohnson(_myVect, 1);
  std::cout << "------------------------------------------" << std::endl;

  printVect(_myVect);
}