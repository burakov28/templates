#pragma once

#include <cxxabi.h>
#include <iostream>
#include <string>

#define DEMANGLE(obj, str_ref)                                                    \
const char *__raw_name = typeid(obj).name();                                      \
const auto __demangler = [raw_name = __raw_name, &str_ref]() {                    \
  int status = 0;                                                                 \
  char *real_name = abi::__cxa_demangle(raw_name, nullptr, nullptr, &status);     \
  str_ref = (status == 0) ? real_name : raw_name;                                 \
  std::free(real_name);                                                           \
};                                                                                \
__demangler()


#define PD(obj)                               \
do {                                          \
  std::string demangled_name;                 \
  DEMANGLE(obj, demangled_name);              \
  std::cout << demangled_name << std::endl;   \
} while (false)
