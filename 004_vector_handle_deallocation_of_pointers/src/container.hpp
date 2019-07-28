#pragma once

#include "data.hpp"

#include <memory>
#include <vector>

class NaiveContainer {
private:
  std::vector<Data *> vec_data;

  static int item_id;

public:
  NaiveContainer(size_t num);
  void add_item();
};

class SharedContainer {
private:
  std::vector<std::shared_ptr<Data>> vec_data;

  static int item_id;

public:
  SharedContainer(size_t num);
  void add_item();
};
