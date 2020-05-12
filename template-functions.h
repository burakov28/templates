#pragma once

#include "demangle.h"

#include <vector>

template<typename T>
void f(std::vector<T> &a) {
  PD(T);
  a.push_back(T());
}

template<typename Q>
void f(std::vector<std::pair<Q, Q>> &a) {

}

template<typename T>
void push_back(std::vector<T> &a, const T &elem) {
  a.push_back(elem);
}



template<typename P, typename Q>
void f(std::pair<std::pair<P, P>, Q> &b) {

}

template<typename T>
void g(const T &a) {
  PD(a);
} // only references
template<typename T>
void p(T *a) {
  PD(a);
} // only pointers

template<typename T>
T min(T a, T b) {
  if (a < b) {
    return a;
  }
  return b;
}

template<typename R, typename T, typename Q>
R fg(T val, T vvalq) {

}

inline void check_functions() {
  std::cout << "Check functions" << std::endl;
  int a;
  int &ref_a = a;
  int *ptr_a = &a;

  //f(a); // [T is int, a is int]
  //f(ref_a); // [T is int, a is int]
  //f(ptr_a); // [T is int *, a is int *]
  std::cout << std::endl;

  g(a); // [T is int, a is int &]
  g(ref_a); // [T is int, a is int &]
  g(ptr_a); // [T is int *, a is int *&]
  std::cout << std::endl;

  // p(a); compilation error
  // p(ref_a);  compilation error
  p(ptr_a); // OK [T is int, a is int *]
  std::cout << std::endl;

  std::cout << std::endl;

  float f = min<double>(5, 0.2);
  fg<double, int, std::string>(0.1, 0.5);
}
