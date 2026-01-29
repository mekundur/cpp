#pragma once

#include <list>
#include <sstream>
#include <string>
#include <vector>

class PmergeMe {

 private:
  std::vector<int> _myVect;
  std::list<int> _myList;
  std::vector<int> _jacobs;
  int _n;

 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void input_check() {}
  void store_numbers(std::string str);
  void generateJacobs();
  void fordJohnson(std::vector<int>& v, int i);
  void sort();

  static void printVect(const std::vector<int>& vect);
  static void printList(const std::list<int>& list);

  class BadInputException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};