#include "Span.hpp"
#include <iostream>
#include <vector>

void print_vect(const std::vector<int>& vect, unsigned int N) {
        std::cout << "_N: " << N << std::endl;
        std::cout << "Size: " << vect.size() << std::endl;
        for (std::vector<int>::const_iterator it = vect.begin(); 
                it != vect.end(); ++it)
                    std::cout << *it << " ";
        std::cout << std::endl;
}

int main()
{
// Test1
    try {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // print_vect(sp.get_numbers(), sp.get_N());
        std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
        std::cout << sp.longestSpan() << " = Longest" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

// Test2
    try {
        Span sp = Span(5);
        
        for (int i = 0; i < 6; i++) {
            if (i % 2)
                sp.addNumber(i * 2);
            else
                sp.addNumber(i * 3);
        }
        // print_vect(sp.get_numbers(), sp.get_N());
        std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
        std::cout << sp.longestSpan() << " = Longest" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

// Test3
    try {
        Span sp = Span(5);
        
        sp.addNumber(1);
        // print_vect(sp.get_numbers(), sp.get_N());
        std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
        std::cout << sp.longestSpan() << " = Longest" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

// Test4
    try {
        Span sp = Span(20000);

        for (int i = 0; i < 20000; i++) {
            if (i % 2)
                sp.addNumber(i * 3);
            else
                sp.addNumber(i * 2);
        }
        // print_vect(sp.get_numbers(), sp.get_N());
        std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
        std::cout << sp.longestSpan() << " = Longest" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

// Test5
    try {
        Span sp = Span(100);
        
        sp.addNumber(1);
        sp.addNumber(2);

        std::vector<int> tmp;
        for (int i = 0; i < 98; i++) {
            if (i % 2)
                sp.addNumber(i * 2);
            else
                sp.addNumber(i * 3);
        }
        sp.addNumber(tmp.begin(), tmp.end());
        // print_vect(sp.get_numbers(), sp.get_N());
        std::cout << sp.shortestSpan() << " = Shortest" << std::endl;
        std::cout << sp.longestSpan() << " = Longest" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}