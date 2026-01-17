#include "easyfind.hpp"
#include "vector"
#include "list"
#include "deque"

int main (void) {

    int num1 = 5, num2 = 100;
    try {
    std::vector<int> myVect;
    for (int i = 1; i <= 5; i++)
            myVect.push_back(i);
    easyfind(myVect, num1);
    easyfind(myVect, num2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
    std::list<int> myList;
    for (int i = 1; i <= 5; i++)
            myList.push_back(i);
    easyfind(myList, num1);
    easyfind(myList, num2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
    std::deque<int> myDeqt;
    for (int i = 1; i <= 5; i++)
            myDeqt.push_back(i);
    easyfind(myDeqt, num1);
    easyfind(myDeqt, num2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
