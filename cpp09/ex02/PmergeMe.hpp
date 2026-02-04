#pragma once

#include <deque>
#include <sstream>
#include <string>
#include <vector>

// global variabels for counting comparasion vsteps
extern int vsteps;
extern int dsteps;

class PmergeMe {

 private:
  std::vector<int> _myVec;
  std::deque<int> _myDeq;
  std::vector<int> _vecResult;
  std::deque<int> _deqResult;

 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  // Getters
  std::vector<int> get_myVec() const;
  std::deque<int> get_myDeq() const;

  // Helper functions
  void store_numbers(const std::string str);
  void sort();
  std::vector<size_t> generateJacobs(size_t n);

  // Vector methods for FordJohson
  void fordJohnson(std::vector<int>& v, int i);
  void jacobsthalInsertion(std::vector<int>& main,
                           const std::vector<int>& mappedSmall);
  void binaryInsertionBound(std::vector<int>& main, size_t up, int val);

  // Deque methods for FordJohson
  void fordJohnson(std::deque<int>& v, int i);
  void jacobsthalInsertion(std::deque<int>& main,
                           const std::deque<int>& mappedSmall);
  void binaryInsertionBound(std::deque<int>& main, size_t up, int value);

  // Utils Functions
  static void printVec(const std::vector<int>& vec);
  static void printVec(const std::vector<size_t>& vec);
  static void printDeq(const std::deque<int>& deq);
  static void printDeq(const std::deque<size_t>& deq);

  // Exceptions
  class BadInputException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

// Extra comparasion functions to compare the efficiency
void linearInsert(std::vector<int>& sorted, int value);
void binaryInsertion(std::vector<int>& main, int val);
double getCurrentTime();
