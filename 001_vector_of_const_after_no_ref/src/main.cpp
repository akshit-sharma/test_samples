#include <iostream>
#include <memory>
#include <vector>

#include <atomic>

class MyVar {
  int *a;

public:
  MyVar();
  MyVar(int val);
  ~MyVar();
};

class GuardMyVar {
  int *a;

  int *counter;

public:
  GuardMyVar();
  GuardMyVar(int val);
  GuardMyVar(const GuardMyVar &val);
  ~GuardMyVar();
};

class SharedMyVar {
  std::shared_ptr<int> a;

public:
  SharedMyVar();
  SharedMyVar(int val);
};

void some_func(const MyVar &orgVar);
void some_func(const GuardMyVar &orgVar);
void some_func(const SharedMyVar &orgVar);

int main(int argc, char *argv[]) {

  MyVar some_var(2);
  GuardMyVar guard_some_var(2);
  SharedMyVar shared_some_var(2);

  // some_func(some_var);
  some_func(guard_some_var);
  // some_func(shared_some_var);

  return 0;
}

// std::atomic<int> GuardMyVar::counter;

void some_func(const MyVar &org_var) {
  std::vector<MyVar> some_vec;
  MyVar new_var(1);

  some_vec.push_back(new_var);
  some_vec.push_back(org_var);

  std::cout << "Size of some_vec (normal) is " << some_vec.size() << std::endl;

  some_vec.clear();
}

void some_func(const GuardMyVar &org_var) {
  std::vector<GuardMyVar> some_vec;
  GuardMyVar new_var(1);

  some_vec.push_back(new_var);
  some_vec.push_back(org_var);

  std::cout << "Size of some_vec (normal) is " << some_vec.size() << std::endl;

  some_vec.clear();
}

void some_func(const SharedMyVar &org_var) {
  std::vector<SharedMyVar> some_vec;
  SharedMyVar new_var(1);

  some_vec.push_back(new_var);
  some_vec.push_back(org_var);

  std::cout << "Size of some_vec (shared) is " << some_vec.size() << std::endl;

  some_vec.clear();
}

MyVar::MyVar() {
  a = new int;
  *a = 0;
}

MyVar::MyVar(int val) : MyVar() { *a = val; }

MyVar::~MyVar() { delete a; }

GuardMyVar::GuardMyVar() {
  a = new int(0);
  counter = new int(1);
  std::cout << "value of counter before was " << *counter << std::endl;
}

GuardMyVar::GuardMyVar(int val) : GuardMyVar() { *a = val; }

GuardMyVar::GuardMyVar(const GuardMyVar &val) {
  a = val.a;
  counter = val.counter;
  (*counter)++;
}

GuardMyVar::~GuardMyVar() {
  if (*counter != 0)
    (*counter)--;
  std::cout << "value of counter after was " << *counter << std::endl;
  if (*counter == 0) {
    delete a;
    delete counter;
  }
}

SharedMyVar::SharedMyVar() {
  a = std::make_shared<int>(0);
  *a = 0;
}

SharedMyVar::SharedMyVar(int val) : SharedMyVar() { *a = val; }
