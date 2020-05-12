#pragma once

#include <iostream>
#include <vector>
#include <set>

#include "demangle.h"

template<typename T>
class A {
public:
  A() :
    a() {
  }

  void f() const {
    PD(a);
  }

private:
  T a;
};

template<>
class A<bool> {   // direct type spec
public:
  A() {
    std::cout << "Bool spec" << std::endl;
  }
};

template<typename P, typename Q> // may have more template args
class A<std::pair<P, Q>> {  // but the same number of args in type
public:
  A() {
    std::cout << "Pair spec" << std::endl;
  }

  std::string field;
};

template<typename P>
class A<std::pair<int, P>> {

};

template<typename Q>
class A<std::pair<Q, int>> {

};

template<>
class A<std::pair<int, int>> {

};

template<typename T>
class A<T *> {    // pointer spec
public:
  A() {
    std::cout << "Pointer spec" << std::endl;
  }
};


// Due to specializations you can implements your class only for some classes or change behavior in some case
template<typename P, typename Q>
class B; // no generic type

template<typename P>
class B<P, bool> {

};

template<typename P>
class B<std::vector<int>, P> {

};

template<>
class B<int, float>;

inline void spec() {
  A<std::pair<int, int>> aaaa;
  A<bool> aa;
  std::pair<int, double> p;
  A<std::set<int>> a;
  a.f();

  A<int *>();

  B<int, bool> bb;
  B<std::vector<int>, double> bbb;
}
