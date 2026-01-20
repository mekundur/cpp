#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void mutate(T& elem) {
  elem++;
}

template <typename T>
void print(const T& elem) {
  std::cout << elem << " ";
}

template <typename T, typename L, typename F>
void iter(T* arr, L len, F func) {
  for (L i = 0; i < len; i++)
    func(arr[i]);
}

#endif