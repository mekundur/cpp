#include <stdint.h>
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {

  uintptr_t uInt = 5;
  Data myData;
  Data* myData_p = NULL;
  myData.name = "Berlin";
  myData.grade = 42;

  std::cout << uInt << std::endl;
  std::cout << &myData << std::endl;
  uInt = Serializer::serialize(&myData);
  std::cout << uInt << std::endl;

  std::cout << myData_p << std::endl;
  myData_p = Serializer::deserialize(uInt);
  std::cout << myData_p << std::endl;
  std::cout << myData_p->grade;
  std::cout << myData_p->name << std::endl;
}