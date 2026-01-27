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

  std::cout << "Before serializing..:" << std::endl;
  std::cout << "uInt: " << uInt << std::endl;
  std::cout << &myData << " Address of data object" << std::endl;

  uInt = Serializer::serialize(&myData);

  std::cout << std::endl;
  std::cout << "After serializing..:" << std::endl;
  std::cout << "uInt: " << uInt << std::endl;


  std::cout << "Before deserializing..:" << std::endl;
  std::cout << myData_p << " Address that pointer to the data object is holding" << std::endl;

  myData_p = Serializer::deserialize(uInt);
  
  std::cout << std::endl;
  std::cout << "After deserializing..:" << std::endl;
  std::cout << &myData << " Address of data object" << std::endl;
  std::cout << myData_p << " Address that pointer to the data object is holding" << std::endl;
  std::cout << myData_p->grade;
  std::cout << myData_p->name << std::endl;
}