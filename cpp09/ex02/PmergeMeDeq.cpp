#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include "PmergeMe.hpp"

int dsteps = 0;

// Insert value into sorted mainChain using full binary search
// (Only for leftover actually)
void binaryInsertion(std::deque<int>& main, int val) {
  size_t low = 0;
  size_t up = main.size();

  while (low < up) {
    size_t mid = (low + up) / 2;
    dsteps++;
    if (main[mid] < val)
      low = mid + 1;
    else
      up = mid;
  }
  main.insert(main.begin() + low, val);
}

// Insert values from small into sorted mainChain using binary insert
// with an upper limit defined by larger pair
void PmergeMe::binaryInsertionBound(std::deque<int>& main, int upperBoundVal,
                                    int val) {
  std::deque<int>::iterator it =
      std::find(main.begin(), main.end(), upperBoundVal);

  size_t up = std::distance(main.begin(), it);
  size_t low = 0;

  while (low < up) {
    size_t mid = (low + up) / 2;
    dsteps++;
    if (main[mid] < val)
      low = mid + 1;
    else
      up = mid;
  }
  main.insert(main.begin() + low, val);
}

// Initialization of insertion by selecting numbers from small
// using Jacobsthal series indexing and bounded binary insertion
void PmergeMe::jacobsthalInsertion(std::deque<int>& main,
                                   const std::deque<int>& large,
                                   const std::deque<int>& small) {

  std::vector<size_t> jacob = generateJacobs(small.size());
  //std::cout << "JACOB_: ";
  // printVec(jacob);

  binaryInsertionBound(main, large[0], small[0]);
  //std::cout << "MCHAIN: ";
  // printDeq(main);

  for (size_t i = 1; i <= jacob.size(); i++) {
    size_t start = jacob[i] - 1;
    size_t end = jacob[i - 1];

    for (size_t index = start; end <= index; index--) {
      if (index < small.size() && index < large.size() && index < main.size()) {
        binaryInsertionBound(main, large[index], small[index]);
      }
    }
  }
}

void PmergeMe::fordJohnson(std::deque<int>& d, int i) {
  if (d.size() < 2)
    return;

  int leftover = 0;
  std::deque<int> large, small, main;

  for (size_t idx = 0; idx < d.size(); idx += 2) {
    if (idx + 1 < d.size()) {
      large.push_back(d[idx] < d[idx + 1] ? d[idx + 1] : d[idx]);
      small.push_back(d[idx] < d[idx + 1] ? d[idx] : d[idx + 1]);
      dsteps++;
    } else {
      leftover = d[idx];
    }
  }
  main = large;

  //std::cout << "RECURSION: ---------------------------------/" << std::setw(2)
  // << i << std::endl;
  //std::cout << "myDeque: ";
  // printDeq(d);
  //std::cout << "_large: ";
  // printDeq(large);
  //std::cout << "_small: ";
  // printDeq(small);
  // if (leftover)
  //std::cout << "LEFTOV: " << leftover << std::endl;

  fordJohnson(main, i + 1);

  //std::cout << "RECURSION: ---------------------------------/" << std::setw(2)
  // << -i << std::endl;
  //std::cout << "_large: ";
  // printDeq(large);
  //std::cout << "_small: ";
  // printDeq(small);
  //std::cout << "MCHAIN: ";
  // printDeq(main);
  // if (leftover)
  //std::cout << "LEFTOV: " << leftover << std::endl;

  jacobsthalInsertion(main, large, small);
  if (leftover) {
    binaryInsertion(main, leftover);
    leftover = 0;
  }
  // for (size_t i = 0; i < small.size(); ++i) {
  //   // linearInsert(main, small[i]);
  //   binaryInsertion(main, small[i]);
  // }
  d = main;
}
