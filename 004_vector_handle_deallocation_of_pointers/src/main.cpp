#include <iostream>

#include "container.hpp"
#include "data.hpp"

int main() {
  std::cout << "Hello\n";
  // NaiveContainer ncontainer(10);

  SharedContainer scontainer(10);

  SharedContainer scon_2 = scontainer;

  std::cout << " World\n";
  return 0;
}
