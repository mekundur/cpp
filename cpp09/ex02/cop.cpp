#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int vsteps = 0;

class PmergeMe {
 public:
  PmergeMe() {}
  ~PmergeMe() {}

  void sortVector(std::vector<int>& data);
  void sortList(std::list<int>& data);

 private:
  // helpers for Ford–Johnson
  void fordJohnsonVector(std::vector<int>& data, int i);
  void fordJohnsonList(std::list<int>& data);
};

void printVec(const std::vector<int>& vect) {
  for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end();
       ++it)
  //std::cout << std::setw(2) << *it << " ";
  //std::cout << std::endl;
}

// Simple insertion helper for vector
void insertVector(std::vector<int>& sorted, int value) {
  std::vector<int>::iterator it = sorted.begin();
  while (it != sorted.end() && *it < value) {
    ++it;
    vsteps++;
  }
  sorted.insert(it, value);
}

// Ford–Johnson for vector
void PmergeMe::fordJohnsonVector(std::vector<int>& data, int i) {
  if (data.size() <= 1)
    return;

  // Step 1: pair up
  int leftover = 0;
  std::vector<int> larger, smaller, main;
  for (size_t i = 0; i < data.size(); i += 2) {
    if (i + 1 < data.size()) {
      int a = data[i], b = data[i + 1];
      if (a > b)
        std::swap(a, b);
      smaller.push_back(a);
      larger.push_back(b);
    } else {
      //leftover = data[i];
      larger.push_back(data[i]);  // odd element
    }
  }
  main = larger;
  //std::cout << "RECURSION: ---------------------------------/" << std::setw(2)
  << i << std::endl;
  //std::cout << "data__: ";
  printVec(data);
  //std::cout << "_large: ";
  printVec(larger);
  //std::cout << "_small: ";
  printVec(smaller);
  if (leftover)
    //std::cout << "leftov: " << leftover << std::endl;

    // Step 2: recursively sort larger
    fordJohnsonVector(main, i + 1);

  //std::cout << "RECURSION: ---------------------------------/" << std::setw(2)
  << -i << std::endl;
  // Step 3: insert smaller into sorted larger
  //std::cout << "_large: ";
  printVec(larger);
  //std::cout << "_small: ";
  printVec(smaller);
  for (size_t i = 0; i < smaller.size(); ++i) {
    insertVector(larger, smaller[i]);
  }
  //  if (leftover)
  //	insertVector(larger, leftover);

  data = main;
  //std::cout << "data__: ";
  printVec(data);
}

// For list, similar but using iterators
void insertList(std::list<int>& sorted, int value) {
  std::list<int>::iterator it = sorted.begin();
  while (it != sorted.end() && *it < value)
    ++it;
  sorted.insert(it, value);
}

void PmergeMe::fordJohnsonList(std::list<int>& data) {
  if (data.size() <= 1)
    return;

  std::list<int> larger, smaller;
  std::list<int>::iterator it = data.begin();
  while (it != data.end()) {
    int a = *it;
    ++it;
    if (it != data.end()) {
      int b = *it;
      ++it;
      if (a > b)
        std::swap(a, b);
      smaller.push_back(a);
      larger.push_back(b);
    } else {
      larger.push_back(a);
    }
  }

  fordJohnsonList(larger);

  //  for (std::list<int>::iterator sit = smaller.begin(); sit != smaller.end();
  //       ++sit) {
  //    insertList(larger, *sit);
  //  }

  data = larger;
}

void PmergeMe::sortVector(std::vector<int>& data) {
  fordJohnsonVector(data, 1);
}

void PmergeMe::sortList(std::list<int>& data) {
  fordJohnsonList(data);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  std::vector<int> vec;
  std::list<int> lst;

  for (int i = 1; i < argc; ++i) {
    int val;
    try {
      val = std::stoi(argv[i]);
      if (val < 0)
        throw std::invalid_argument("negative");
    } catch (...) {
      std::cerr << "Error" << std::endl;
      return 1;
    }
    vec.push_back(val);
    lst.push_back(val);
  }

  //std::cout << "Before: ";
  for (size_t i = 0; i < vec.size(); ++i)
    //std::cout << vec[i] << " ";
    //std::cout << std::endl;
    //std::cout << "------------------------------------------" << std::endl;

    clock_t start = clock();
  PmergeMe pm;

  pm.sortVector(vec);
  clock_t end = clock();
  double vecTime = double(end - start) / CLOCKS_PER_SEC * 1e6;

  //std::cout << "------------------------------------------" << std::endl;
  //std::cout << "After: ";
  for (size_t i = 0; i < vec.size(); ++i)
    //std::cout << vec[i] << " ";
    //std::cout << std::endl;

    start = clock();
  pm.sortList(lst);
  end = clock();
  double listTime = double(end - start) / CLOCKS_PER_SEC * 1e6;

  //std::cout << "Time to process a range of " << vec.size()
  << " elements with std::vector : " << vecTime << " us" << std::endl;
  //std::cout << "Time to process a range of " << lst.size()
  << " elements with std::list   : " << listTime << " us" << std::endl;
  //std::cout << "vsteps: " << vsteps << std::endl;
}
