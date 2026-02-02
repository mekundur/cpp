#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  if (argc < 3)
    return (std::cout << "Please pass a set of poisitive integers\n", 0);
  try {
    PmergeMe pm;
    int i = 1;
    while (i < argc)
      pm.store_numbers(argv[i++]);
    pm.sort();

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}