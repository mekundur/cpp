#pragma once

#include <vector>

class Span {

    private: 
        unsigned int        _N;
        std::vector<int>    _numbers;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();

        void addNumber(int n); 
        void addNumber(std::vector<int>::const_iterator first, 
                        std::vector<int>::const_iterator last);

        unsigned int get_N() const;
        const std::vector<int>& get_numbers() const;
        
        int shortestSpan() const;
        int longestSpan() const;

        class NotEnoughNumbersException : public std::exception {
            virtual const char* what () const throw() {
                return("Not enough numbers");
            }
        };    
        
        class MaxElementsException : public std::exception {
            virtual const char* what() const throw() {
                return("Max size (_N) is reached!");
            }
        };

};