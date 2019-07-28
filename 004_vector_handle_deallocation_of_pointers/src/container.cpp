#include "container.hpp"

#include <iostream>

int NaiveContainer::item_id = 100;

NaiveContainer::NaiveContainer(size_t num) {
  vec_data.reserve(num);
  for (size_t i = 0; i < num; ++i) {
    add_item();
  }
}

void NaiveContainer::add_item() {
  vec_data.push_back(new Data(item_id));
  item_id++;
}

int SharedContainer::item_id = 200;

SharedContainer::SharedContainer(size_t num) {
  vec_data.reserve(num);
  for (size_t i = 0; i < num; ++i) {
    add_item();
  }
}

void SharedContainer::add_item() {
  vec_data.push_back(std::make_shared<Data>(item_id));
  item_id++;
}
