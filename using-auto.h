#pragma once

#include <iostream>

#include "demangle.h"

inline void using_auto() {
  std::cout << "Using auto" << std::endl;
  // auto discard &
  int a;
  int &ref_a = a;

  auto b = a; // b is int
  auto bb = ref_a; // bb is int
  auto &bbb = a; // bbb is int &
  auto &bbbb = ref_a; // bbbb is int &

  auto c = &a; // c is int *
  auto *cc = &a; // cc is int *

  const int d = 10;
  auto e = d; // e is int
  const auto ee = d; // ee is const int

  auto &eee = d; // eee is const int &

  std::cout << std::endl;
}
