#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
#include "PmergeMe.hpp"

void PmergeMe::printVect(const std::vector<int>& vect) {
  for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end();
       ++it)
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::printList(const std::list<int>& list) {
  for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}