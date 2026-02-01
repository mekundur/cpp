#pragma once

#include <list>
#include <sstream>
#include <string>
#include <vector>

extern int steps;

class PmergeMe {

 private:
  std::vector<int> _myVect;
  std::list<int> _myList;

 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  // Getters
  std::vector<int> get_myVect() const;
  std::list<int> get_myList() const;

  // Entrypoint functions
  void store_numbers(const std::string str);
  void sort();

  // Vector methods for FordJohson
  void fordJohnson(std::vector<int>& v, int i);
  std::vector<size_t> generateJacobs(size_t n);
  void binaryInsertionBound(std::vector<int>& main, int upperBoundVal, int val);
  void jacobsthalInsertion(std::vector<int>& main,
                           const std::vector<int>& large,
                           const std::vector<int>& small, int& leftover);

  // Utils Functions
  static void printVect(const std::vector<int>& vect);
  static void printVect(const std::vector<size_t>& vect);
  static void printList(const std::list<int>& list);

  // Exceptions
  class BadInputException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

// Extra comparasion functions to compare the efficiency
void linearInsert(std::vector<int>& sorted, int value);
void binaryInsertion(std::vector<int>& main, int val);
