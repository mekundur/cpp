#include "deque"
#include "easyfind.hpp"
#include "list"
#include "vector"

int main(void) {

  int num1 = 5, num2 = 100;
  try {
    std::vector<int> myVect;
    for (int i = 1; i <= 5; i++)
      myVect.push_back(i);
    easyfind(myVect, num1);
    easyfind(myVect, num2);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::list<int> myList;
    for (int i = 1; i <= 5; i++)
      myList.push_back(i);
    easyfind(myList, num1);
    easyfind(myList, num2);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::deque<int> myDeq;
    for (int i = 1; i <= 5; i++)
      myDeq.push_back(i);
    easyfind(myDeq, num1);
    easyfind(myDeq, num2);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
