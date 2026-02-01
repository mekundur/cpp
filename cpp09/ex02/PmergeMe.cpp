#include "PmergeMe.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
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

// Getters
std::vector<int> PmergeMe::get_myVect() const {
  return (_myVect);
}

std::list<int> PmergeMe::get_myList() const {
  return (_myList);
}

// Start of recursive sorting
void PmergeMe::sort() {

  std::cout << "------------------------------------------" << std::endl;
  fordJohnson(_myVect, 1);
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "_RESULT: ";
  std::cout << "STEPS: " << steps << std::endl;
  printVect(_myVect);

  ////// LIST SORTING WILL BE HERE
}

// Input parsing and storing:
void PmergeMe::store_numbers(const std::string str) {
  std::stringstream ss(str);
  std::string token;

  while (ss >> token) {
    for (size_t i = 0; i < token.size(); ++i) {
      if (!std::isdigit(token[i]))
        throw BadInputException();
    }
    if (token.size() > 10)
      throw BadInputException();
    if (token.size() == 10 && token > "2147483647")
      throw BadInputException();
    int value = std::atoi(token.c_str());
    if (value <= 0)
      throw BadInputException();

    _myVect.push_back(value);
    _myList.push_back(value);
  }
}

// Exceptions
const char* PmergeMe::BadInputException::what() const throw() {
  return ("Error: Bad input");
}

/////
// void PmergeMe::binaryInsertionBound(std::vector<int>& main, int upperBoundVal,
//                                     int val) {
//   std::vector<int>::iterator it =
//       std::find(main.begin(), main.end(), upperBoundVal);
//   size_t up = std::distance(main.begin(), it);
//   size_t low = 0;

//   while (low < up) {
//     size_t mid = (low + up) / 2;
//     steps++;
//     if (main[mid] < val)
//       low = mid + 1;
//     else
//       up = mid;
//   }
//   main.insert(main.begin() + low, val);
// }
// //////////////////////
// void PmergeMe::jacobsthalInsertion(std::vector<int>& main,
//                                    const std::vector<int>& large,
//                                    const std::vector<int>& small,
//                                    int& leftover) {

//   std::vector<size_t> jacob = generateJacobs(small.size());
//   std::cout << "JACOB_: ";
//   printVect(jacob);

//   binaryInsertionBound(main, large[0], small[0]);
//   std::cout << "MCHAIN: ";
//   printVect(main);

//   for (size_t i = 1; i <= jacob.size(); i++) {
//     size_t start = jacob[i] - 1;
//     size_t end = jacob[i - 1];
//     for (size_t index = start; end <= index; index--) {
//       if (index < small.size() && index < large.size() && index < main.size()) {
//         binaryInsertionBound(main, large[index], small[index]);
//       }
//     }
//     if (leftover) {
//       binaryInsertion(main, leftover);
//       leftover = 0;
//     }
//   }
// }

// void PmergeMe::fordJohnson(std::vector<int>& v, int i) {
//   if (v.size() < 2)
//     return;
//   int leftover = 0;
//   std::vector<int> large, small, main;
//   for (size_t i = 0; i < v.size(); i += 2) {
//     if (i + 1 < v.size()) {
//       large.push_back(v[i] < v[i + 1] ? v[i + 1] : v[i]);
//       small.push_back(v[i] < v[i + 1] ? v[i] : v[i + 1]);
//       steps++;
//     } else
//       leftover = v[i];
//   }
//   main = large;
//   std::cout << "RECURSION: ---------------------------------/" << std::setw(2)
//             << i << std::endl;
//   std::cout << "myVect: ";
//   printVect(v);
//   std::cout << "_large: ";
//   printVect(large);
//   std::cout << "_small: ";
//   printVect(small);
//   if (leftover)
//     std::cout << "LEFTOV: " << leftover << std::endl;

//   fordJohnson(main, i + 1);

//   std::cout << "RECURSION: ---------------------------------/" << std::setw(2)
//             << -i << std::endl;
//   std::cout << "_large: ";
//   printVect(large);
//   std::cout << "_small: ";
//   printVect(small);
//   std::cout << "MCHAIN: ";
//   printVect(main);
//   if (leftover)
//     std::cout << "LEFTOV: " << leftover << std::endl;

//   jacobsthalInsertion(main, large, small, leftover);

//   // for (size_t i = 0; i < small.size(); ++i) {
//   //   // linearInsert(main, small[i]);
//   //   binaryInsertion(main, small[i]);
//   // }
//   v = main;
// }
