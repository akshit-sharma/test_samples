#include "data.hpp"
#include <iostream>

Data::Data(int value) : item(value) {
  std::cout << "Contructing data with " << item << std::endl;
}

Data::~Data() { std::cout << "Destructing data with " << item << std::endl; }

int Data::getValue() { return item; }
