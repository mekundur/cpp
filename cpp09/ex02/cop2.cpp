#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class PmergeMe {
 public:
  PmergeMe() {}
  ~PmergeMe() {}

  void sortVector(std::vector<int>& data);

 private:
  // helpers for Ford–Johnson
  void fordJohnsonVector(std::vector<int>& data, int i);
};

void printVect(const std::vector<int>& vect) {
  for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end();
       ++it)
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

////////////////////
// Struct to preserve pairing
struct Pair {
  int small;
  int large;
};

void printPairs(const std::vector<Pair>& p) {
  std::cout << "pLarge: ";
  for (std::vector<Pair>::const_iterator it = p.begin(); it != p.end(); ++it)
    std::cout << std::setw(2) << it->large << " ";
  std::cout << std::endl;

  std::cout << "pSmall: ";
  for (std::vector<Pair>::const_iterator it = p.begin(); it != p.end(); ++it)
    std::cout << std::setw(2) << it->small << " ";
  std::cout << std::endl;
}

// Jacobsthal sequence generator up to limit n
std::vector<size_t> jacobsthalSequence(size_t n) {
  std::vector<size_t> seq;
  seq.push_back(0);
  seq.push_back(1);
  while (seq.back() < n) {
    size_t k = seq.size();
    seq.push_back(seq[k - 1] + 2 * seq[k - 2]);
  }
  return seq;
}

// Insert with bound using lower_bound
void insertWithBound(std::vector<int>& backbone, int value, int bound) {
  // find the partner's position in the backbone
  auto boundPos = std::find(backbone.begin(), backbone.end(), bound);
  if (boundPos == backbone.end()) {
    // fallback: if bound not found, search whole backbone
    boundPos = backbone.end();
  }
  // lower_bound does binary search automatically
  auto pos = std::lower_bound(backbone.begin(), boundPos + 1, value);
  backbone.insert(pos, value);
}
//////////////////////////
// Ford–Johnson for vector
void PmergeMe::fordJohnsonVector(std::vector<int>& data, int i) {
  if (data.size() <= 1)
    return;

  // Step 1: form pairs
  int leftover = 0;
  std::vector<int> mainChain, smaller;
  std::vector<Pair> pairs;
  for (size_t i = 0; i < data.size(); i += 2) {
    if (i + 1 < data.size()) {
      int a = data[i], b = data[i + 1];
      if (a > b)
        std::swap(a, b);
      pairs.push_back({a, b});
    } else {
      // odd leftover goes into larger backbone directly
      // pairs.push_back({data[i], data[i]});  // treat as small=large
      leftover = data[i];
    }
  }

  std::cout << "RECURSION-----------------------------------/" << std::setw(2)
            << i << std::endl;
  std::cout << "data__: ";
  printVect(data);
  printPairs(pairs);
  if (leftover)
    std::cout << "leftov: " << leftover << std::endl;

  for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end();
       ++it) {
    mainChain.push_back(it->large);
  }
  if (leftover)
    mainChain.push_back(leftover);
  // Step 2: recursively sort larger

  fordJohnsonVector(mainChain, i + 1);

  std::cout << "RECURSION-----------------------------------/" << std::setw(2)
            << -i << std::endl;

  printPairs(pairs);
  std::cout << "MCHAIN: ";
  printVect(mainChain);

  // Step 3: insert smaller using Jacobsthal order
  std::vector<size_t> jac = jacobsthalSequence(pairs.size());
  size_t inserted = 0;
  for (size_t j = 1; j < jac.size() && inserted < pairs.size(); ++j) {
    size_t idx = std::min(jac[j], pairs.size());
    for (size_t k = idx; k > jac[j - 1]; --k) {
      if (k <= pairs.size()) {
        int val = pairs[k - 1].small;
        int bound = pairs[k - 1].large;
        insertWithBound(mainChain, val, bound);
        ++inserted;
      }
    }
  }
  // if (leftover)
  //   insertVector(larger, leftover);

  data = mainChain;
  std::cout << "data__: ";
  printVect(data);
}

void PmergeMe::sortVector(std::vector<int>& data) {
  fordJohnsonVector(data, 1);
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

  std::cout << "Before: ";
  for (size_t i = 0; i < vec.size(); ++i)
    std::cout << vec[i] << " ";
  std::cout << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  clock_t start = clock();
  PmergeMe pm;

  pm.sortVector(vec);
  clock_t end = clock();
  double vecTime = double(end - start) / CLOCKS_PER_SEC * 1e6;

  std::cout << "------------------------------------------" << std::endl;
  std::cout << "After: ";
  for (size_t i = 0; i < vec.size(); ++i)
    std::cout << vec[i] << " ";
  std::cout << std::endl;

  std::cout << "Time to process a range of " << vec.size()
            << " elements with std::vector : " << vecTime << " us" << std::endl;
}
