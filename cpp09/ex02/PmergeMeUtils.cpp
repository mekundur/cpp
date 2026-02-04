#include <sys/time.h>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

void PmergeMe::printVec(const std::vector<int>& vec) {
  for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::printVec(const std::vector<size_t>& vec) {
  for (std::vector<size_t>::const_iterator it = vec.begin(); it != vec.end();
       ++it)
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::printDeq(const std::deque<int>& deq) {
  for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::printDeq(const std::deque<size_t>& deq) {
  for (std::deque<size_t>::const_iterator it = deq.begin(); it != deq.end();
       ++it)
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

/** 
 * @brief generating original Jacobsthal series and the cutting the first two elements {0, 1}
 */
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

double getCurrentTime() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

// Insertion Sort
void linearInsert(std::vector<int>& sorted, int value) {
  std::vector<int>::iterator it = sorted.begin();
  while (it != sorted.end()) {
    vsteps++;
    if (*it < value)
      ++it;
    else
      break;
  }
  sorted.insert(it, value);
}

// Insert value into sorted mainChain using full binary search
void binaryInsertion(std::vector<int>& main, int val) {
  size_t low = 0;
  size_t up = main.size();

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

// Insert value into sorted mainChain using full binary search
void binaryInsertion(std::deque<int>& main, int val) {
  size_t low = 0;
  size_t up = main.size();

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