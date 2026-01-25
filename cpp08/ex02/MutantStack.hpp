#pragma once

#include <iterator>
#include <list>
#include <stack>

/**
 * @brief Following is the definition of std::stack template from stl_stack.h:
 * 
 *  template<typename _Tp, typename _Sequence = deque<_Tp> >
    class stack
    {
      template<typename _Tp1, typename _Seq1>
        public:
           typedef	       _Sequence			container_type;
        protected:
          // See queue::c for notes on this name.
            _Sequence c;
 */

template <typename T>
class MutantStack : public std::stack<T> {

 public:
  MutantStack() {}
  MutantStack(const MutantStack& other) : std::stack<T>(other) {}
  MutantStack& operator=(const MutantStack& other) {
    if (this != &other)
      std::stack<T>::operator=(other);
    return (*this);
  }
  ~MutantStack() {}

  typedef typename std::stack<T>::container_type::iterator iterator;

  iterator begin() { return (this->c.begin()); }

  iterator end() { return (this->c.end()); }
};