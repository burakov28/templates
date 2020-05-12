#pragma once

#include <vector>
#include <set>

#include "demangle.h"

template<typename A, typename B>
class pair_t {
public:
  pair_t() :
    first(),
    second() {}

  pair_t(const A &a, const B &b) :
    first(a),
    second(b) {
    a.size();
  }

  A first;
  B second;
};

template<typename A, typename B>
pair_t<A, B> make_paiir(const A &a, const B &b) { // function can deduce types automatically
  return pair_t<A, B>(a, b);
}

class tmp {
public:
  tmp() = default;
  tmp(const tmp &) = delete;
};

inline void f() {

  pair_t<int, double> p;
  std::vector<int> vv;
  auto pp = make_paiir(vv, 0.5);
  PD(pp);
  p.first = 10;
  p.second = 0.5;
}
