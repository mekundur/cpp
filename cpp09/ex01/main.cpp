#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2)
    return (std::cout << "Please pass an RPN expression to calculate in double "
                         "quotes such as: \"7 7 * 7 -\"\n",
            0);
  try {
    RPN myRPN;
    myRPN.calculate(argv[1]);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}