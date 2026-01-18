#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>
#include <iterator>
#include <cstdlib>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span &other) {
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

void Span::addNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last) {
    if ((_numbers.size() + std::distance(first, last)) > _N )
        throw MaxElementsException();
    _numbers.insert(_numbers.end(), first, last);
}

unsigned int Span::get_N() const {
    return (_N);
}

const std::vector<int>& Span::get_numbers() const {
    return (_numbers);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw (NotEnoughNumbersException());
    
    std::vector<int>::const_iterator it1 = _numbers.begin();
    std::vector<int>::const_iterator it2 = _numbers.begin() + 1;
    int span = abs(*it1 - *it2);
    for (; it1 != _numbers.end(); it1++) {
        it2 = it1 + 1;
        for (; it2 != _numbers.end(); it2++) {
            if (abs(*it1 - *it2) < span)
                span = abs(*it1 - *it2);
        }
    }
    return (span);
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw (NotEnoughNumbersException());
    
    int span = 0;
    std::vector<int>::const_iterator it1 = _numbers.begin();
    for (; it1 != _numbers.end(); ++it1) {
        std::vector<int>::const_iterator it2 = _numbers.begin();
            for (; it2 != _numbers.end(); ++it2) {
                if (abs(*it1 - *it2) > span)
                span = abs(*it1 - *it2);
            }
    }
    return (span);
}