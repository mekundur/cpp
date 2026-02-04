#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
#include "PmergeMe.hpp"

int vsteps = 0;

// Insert values from small into sorted mainChain using binary insert
// with an upper limit defined by larger pair
void PmergeMe::binaryInsertionBound(std::vector<int>& main, size_t up,
                                    int val) {
  size_t low = 0;

  while (low < up) {
    size_t mid = (low + up) / 2;
    if (main[mid] < val)
      low = mid + 1;
    else
      up = mid;
    vsteps++;
  }
  main.insert(main.begin() + low, val);
}

// Initialization of insertion by selecting numbers from small
// using Jacobsthal series indexing and bounded binary insertion
void PmergeMe::jacobsthalInsertion(std::vector<int>& main,
                                   const std::vector<int>& mappedSmall) {
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

void PmergeMe::fordJohnson(std::vector<int>& v, int i) {
  if (v.size() < 2)
    return;

  std::vector<int> large, small, main;

  for (size_t i = 0; i < v.size(); i += 2) {
    if (i + 1 < v.size()) {
      large.push_back(v[i] < v[i + 1] ? v[i + 1] : v[i]);
      small.push_back(v[i] < v[i + 1] ? v[i] : v[i + 1]);
      vsteps++;
    } else
      small.push_back(v[i]);
  }

  main = large;
  fordJohnson(main, i + 1);

  std::vector<int> mappedSmall;
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

  jacobsthalInsertion(main, mappedSmall);

  v = main;
}
