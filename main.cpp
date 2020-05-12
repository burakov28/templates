#include "template-functions.h"
#include "using-auto.h"
#include "lambdas.h"
#include "template-specialization.h"
#include "simple-template-class.h"

int main() {
  f();
  spec();

  check_functions();
  using_auto();
  lambdas();
  check_functional_objects();
  return 0;
}
