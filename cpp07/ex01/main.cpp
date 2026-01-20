#include <iostream>
#include <string>
#include "iter.hpp"

int main(void) {
  {
    int len = 5;
    const int arr[5] = {0, 5, 8, 3};

    // iter(arr, len, mutate<const int>);
    iter(arr, len, print<const int>);
    for (int i = 0; i < len; i++)
      std::cout << arr[i] << " ";
    std::cout << std::endl;
  }
  {
    size_t len = 5;
    double arr[5] = {1.3, 5.5, 3.14, 35.99, 19.89};

    iter(arr, len, mutate<double>);
    for (size_t i = 0; i < len; i++)
      std::cout << arr[i] << " ";
    std::cout << std::endl;
  }
  {
    size_t len = 10;
    char arr[10] = "Mertcan";

    iter(arr, len, mutate<char>);
    for (size_t i = 0; i < len; i++)
      std::cout << arr[i] << " ";
    std::cout << std::endl;
  }
  {
    unsigned int len = 3;
    std::string arr[3] = {"42", "Berlin", "is the best"};

    iter(arr, len, print<std::string>);
    std::cout << std::endl;
  }
  return (0);
}