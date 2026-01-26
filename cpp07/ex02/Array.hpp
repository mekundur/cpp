#pragma once

#define ARRAY_HPP
#include <exception>
#include <iostream>
#include <string>

template <typename T>
class Array {

 private:
  T* _data;
  unsigned int _len;

 public:
  Array<T>() : _len(0), _data(NULL){};

//   Array(unsigned int n) : _len(n), _data(new T[_len]){};
  
  Array(unsigned int n) {
    _len = n;
    _data = new T[_len];
  };

  Array(const Array& other) : _len(other._len) {
    _data = new T[_len];
    for (unsigned int i = 0; i < _len; i++)
      _data[i] = other._data[i];
  };

  Array& operator=(const Array& other) {
    if (this != &other) {
      this->_len = other._len;
      delete[] this->_data;
      this->_data = new T[_len];
      for (unsigned int i = 0; i < _len; i++)
        _data[i] = other._data[i];
    }
    return (*this);
  };

  ~Array() { delete[] _data; };

  // getters
  unsigned int size() const { return (_len); }

  // overloading of [] operator to access array elements
  T& operator[](int i) { return (_data[check(i)]); };

  const T& operator[](int i) const { return (_data[check(i)]); };

  // index bounds checking method and exception:
  int check(int i) const {
    if (i < 0 || i >= (int)_len)
      throw BoundsViolationException();
    return (i);
  };

  class BoundsViolationException : public std::exception {
   public:
    virtual const char* what() const throw() {
      return ("Index is out of bounds!");
    };
  };
};

// My class array implementation (not the template one)

/*
class Array {
    
    private:
        unsigned int    _len;
        int             *_data;

    public:
        unsigned int    size() {
            return (_len); 
        } 

        Array() : _len(0), _data(new int[_len]) {};
        Array(unsigned int n) : _len(n), _data(new int[_len]) {};
        Array(const Array& other) : _len(other._len) {
            _data = new int[_len];
            for(unsigned int i = 0; i < _len; i++)
                _data[i] = other._data[i];
        };
        Array& operator=(const Array& other) {
            if (this != &other) {
                this->_len = other._len;
                delete[] _data;
                _data = new int[_len];
                for (unsigned int i = 0; i < _len; i++)
                    _data[i] = other._data[i];
            }
            return (*this);
        };

        int& operator[](int i) {
            return (_data[check(i)]);
        };

        ~Array() {delete[] _data;};

        int check(int i) {
            if (i < 0 || i >= (int)_len)
                throw BoundsViolationException();
            return (i);
        };

        class   BoundsViolationException : public std::exception {
            public:
                virtual const char* what() const throw () {
                    return ("Index is out bounds!");
                };
        };

};
*/