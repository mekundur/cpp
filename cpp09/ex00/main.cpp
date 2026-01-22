#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2)
    return (std::cout << "Please pass a single input file\n", 0);
  try {
    BitcoinExchange myCoin;
    myCoin.store_data();
    myCoin.get_inputs(argv[1]);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}