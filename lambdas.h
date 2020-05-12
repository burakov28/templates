#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <set>

class Func {
public:
  Func(int &a, int b, int d) : a(a), b(b), d(d) {}

  std::string operator()(std::vector<int> &v, const std::string &str) /* if no mutable than this method is const */ {
    // body
  }
private:
  int &a;
  int b;
  int d;
};

auto f() {
  int a = 0;
  return [a] () {
    return a + 1;
  };
}

inline void lambdas() {
  std::cout << "Check lambdas" << std::endl;
  // [] -- capture (here you describe all vars from context) () -- args (same as function args) {
  //
  // }

  // [=] -- get all context by value
  // [&] -- get all context by reference

  int a = 1;
  const auto ref_capture = [&]() { // no mutable because you capture reference and change value by reference NOT reference
    ++a;
  };
  ref_capture();
  std::cout << a << std::endl; // 2
  auto value_capture = [=]() mutable { // mutable to change CAPTURED values
    ++a;
  };
  value_capture();
  std::cout << a << std::endl; // also 2

  // auto func = [&a, b, d](std::vector<int> &v, const std::string &str) -> std::string 'with mutable/without mutable' {
  //    body
  // }
  // func(your_vector, your_string);
  // equivalent to
  // auto func = Func(a, b, d);
  // func(your_vector, your_string);
  std::cout << std::endl;
}

float ffs(const std::vector<double> &v, double e) {
  return 0.0;
}

template<typename T>
T call(std::function<T()> f) {
  return f();
}

inline void check_functional_objects() {
  std::cout << "Check functional objects" << std::endl;
  std::function<int(int &, const std::vector<std::string> &)> f;
  // functional is wrapper for all callable objects. can store funtcions, lambdas, all objects with appropriate operator()

  std::function<float(const std::vector<double> &v, double e)> f1 = ffs;
  int a = 0;
  int b = 5;
  int d = 7;
  std::function<std::string(std::vector<int> &, const std::string &)> f2 = Func(a, b, d);
  std::function<bool(int, int)> f3 = [](int aa, int bb) {
    return aa == bb;
  };

  std::function<int()> f4 = []() {
    return 10;
  };
  call(f4);

  std::vector<int> vvv = {4, 2, 7, 3};
  std::sort(vvv.begin(), vvv.end(), [](int a, int b) {
    if (a % 2 != b % 2) {
      return a % 2 < b % 2;
    }
    return a < b;
  });

  std::all_of(vvv.begin(), vvv.end(), [](int a) {
    return a % 2 == 0;
  });

  const auto comp = [](int a, int b) {
    return a % 10 < b % 10;
  };
  std::set<int, std::function<bool(int, int)>> sst(comp);
  // you can pass function as argument -- the most comfortable way to pass function to other function
  std::cout << std::endl;
}
