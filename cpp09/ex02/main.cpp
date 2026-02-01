#include <iostream>
#include <list>
#include <vector>
#include "PmergeMe.hpp"

// int steps;

int main(int argc, char** argv) {
  if (argc != 2)
    return (std::cout << "Please pass a set of poisitive integers\n", 0);
  try {
    PmergeMe pm;
    pm.store_numbers(argv[1]);
    pm.sort();

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}