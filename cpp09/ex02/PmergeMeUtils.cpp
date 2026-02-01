#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
#include "PmergeMe.hpp"

// void PmergeMe::printVect(const std::vector<int>& vect) {
//   for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end();
//        ++it)
//     std::cout << std::setw(2) << *it << " ";
//   std::cout << std::endl;
// }

void PmergeMe::printList(const std::list<int>& list) {
  for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

///// Move both printVect functions into utils later on
void PmergeMe::printVect(const std::vector<int>& vect) {
  for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end();
       ++it)
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::printVect(const std::vector<size_t>& vect) {
  for (std::vector<size_t>::const_iterator it = vect.begin(); it != vect.end();
       ++it)
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

/////
////////////////////// Insertion Sort
void linearInsert(std::vector<int>& sorted, int value) {
  std::vector<int>::iterator it = sorted.begin();
  while (it != sorted.end()) {
    steps++;  // count every comparison attempt
    if (*it < value)
      ++it;
    else
      break;
  }
  sorted.insert(it, value);
}
////////////////////// Binary Insertion Sort
// Insert value into sorted mainChain using full binary search
void binaryInsertion(std::vector<int>& main, int val) {
  size_t low = 0;
  size_t up = main.size();

  while (low < up) {
    size_t mid = (low + up) / 2;
    steps++;
    if (main[mid] < val)
      low = mid + 1;
    else
      up = mid;
  }
  main.insert(main.begin() + low, val);
}

std::vector<size_t> PmergeMe::generateJacobs(size_t n) {
  std::vector<size_t> jacobs;
  jacobs.push_back(0);
  jacobs.push_back(1);
  for (int i = jacobs.size(); jacobs.back() < n;) {
    jacobs.push_back(jacobs[i - 2] * 2 + jacobs[i - 1]);
    i = jacobs.size();
  }
  jacobs.erase(jacobs.begin());
  jacobs.erase(jacobs.begin());
  return (jacobs);
}