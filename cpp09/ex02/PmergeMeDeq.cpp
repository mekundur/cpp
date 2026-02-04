#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include "PmergeMe.hpp"

int dsteps = 0;

// Insert values from small into sorted mainChain using binary insert
// with an upper limit defined by larger pair
void PmergeMe::binaryInsertionBound(std::deque<int>& main, size_t up, int val) {
  size_t low = 0;

  while (low < up) {
    size_t mid = (low + up) / 2;
    if (main[mid] < val)
      low = mid + 1;
    else
      up = mid;
    dsteps++;
  }
  main.insert(main.begin() + low, val);
}

// Initialization of insertion by selecting numbers from small
// using Jacobsthal series indexing and bounded binary insertion
void PmergeMe::jacobsthalInsertion(std::deque<int>& main,
                                   const std::deque<int>& mappedSmall) {
  std::vector<size_t> jacob = generateJacobs(mappedSmall.size());
  //std::cout << "JACOB_: ";
  // printVec(jacob);

  main.insert(main.begin(), mappedSmall[0]);
  // binaryInsertionBound(main, 0, mappedSmall[0]);

  for (size_t i = 1; i < jacob.size(); ++i) {
    size_t k = i + 1;

    size_t start = jacob[i] - 1;
    size_t end = jacob[i - 1];

    size_t limit = ((1 << k) - 1);  // formulating (2^k - 1) by bit shifting
    // std::cout << "k = " << k << ", limit = ((1 << k) - 1) = " << limit
    //           << std::endl;
    size_t upperBound = (limit < main.size()) ? limit : main.size();
    if (upperBound > main.size())
      upperBound = main.size();

    // loop for iterating among the elements that defined and
    // passed by Jaconshtal indexing e.g. (k = 2, elements: [3,2])
    for (size_t index = start; end <= index; --index) {
      // std::cout << "jacobs' index: " << index << std::endl;
      if (index < mappedSmall.size()) {
        binaryInsertionBound(main, upperBound, mappedSmall[index]);
      }
    }
  }
}

void PmergeMe::fordJohnson(std::deque<int>& d, int i) {
  if (d.size() < 2)
    return;

  std::deque<int> large, small, main;

  for (size_t i = 0; i < d.size(); i += 2) {
    if (i + 1 < d.size()) {
      large.push_back(d[i] < d[i + 1] ? d[i + 1] : d[i]);
      small.push_back(d[i] < d[i + 1] ? d[i] : d[i + 1]);
      dsteps++;
    } else
      small.push_back(d[i]);
  }

  //////
  // std::cout << "---RECURSION: ---------------------------------/"
  //           << std::setw(2) << i << std::endl;
  // std::cout << "myDeque: ";
  // printDeq(d);
  // std::cout << "_small: ";
  // printDeq(small);
  // std::cout << "_large: ";
  // printDeq(large);

  main = large;
  fordJohnson(main, i + 1);

  // /////// MAPPING / ALIGNING of small set and creating mappedSmall
  std::deque<int> mappedSmall;
  mappedSmall.clear();
  mappedSmall.resize(main.size());
  for (size_t i = 0; i < main.size(); ++i) {
    for (size_t j = 0; j < large.size(); ++j) {
      if (main[j] == large[i]) {
        mappedSmall[j] = small[i];
        break;
      }
    }
  }
  if (small.size() > large.size())
    mappedSmall.push_back(small.back());

  //////
  // std::cout << "---RECURSION: ---------------------------------/"
  //           << std::setw(2) << -i << std::endl;
  // std::cout << "_small: ";
  // printDeq(small);
  // std::cout << "_large: ";
  // printDeq(large);
  // std::cout << "MCHAIN: ";
  // printDeq(main);
  // std::cout << "mapped: ";
  // printDeq(mappedSmall);

  jacobsthalInsertion(main, mappedSmall);

  // std::cout << "MCHAIN: ";
  // printDeq(main);
  // for (size_t i = 0; i < small.size(); ++i) {
  //   // linearInsert(main, small[i]);
  //   binaryInsertion(main, small[i]);
  // }
  d = main;
}
