#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <iterator>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    this->_N = other._N;
    this->_numbers = other._numbers;
  }
  return (*this);
}

Span::~Span() {}

void Span::addNumber(int n) {
  if (_numbers.size() < _N)
    _numbers.push_back(n);
  else
    throw MaxElementsException();
}

void Span::addNumber(std::vector<int>::const_iterator first,
                     std::vector<int>::const_iterator last) {
  if ((_numbers.size() + std::distance(first, last)) > _N)
    throw MaxElementsException();
  _numbers.insert(_numbers.end(), first, last);
}

unsigned int Span::get_N() const {
  return (_N);
}

const std::vector<int>& Span::get_numbers() const {
  return (_numbers);
}

void Span::printVect() const {
  std::cout << "_N: " << _N << std::endl;
  std::cout << "Size: " << _numbers.size() << std::endl;
  for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end();
       ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}


int Span::shortestSpan() const {
  if (_numbers.size() < 2)
    throw(NotEnoughNumbersException());

  std::vector<int> tmp(_numbers);
  std::sort(tmp.begin(), tmp.end());
  int span = tmp.back() - tmp.front();
    for (std::vector<int>::iterator it = tmp.begin(); (it + 1) != tmp.end(); ++it) {
      if (abs(*(it + 1) - *it) < span)
        span = abs(*(it + 1) - *it);    
    }
  return (span);
}

int Span::longestSpan() const {
  if (_numbers.size() < 2)
    throw(NotEnoughNumbersException());

  std::vector<int> tmp(_numbers);
  std::sort(tmp.begin(), tmp.end());

  return (tmp.back() - tmp.front());
}