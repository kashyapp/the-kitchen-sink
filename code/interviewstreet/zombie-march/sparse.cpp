#include "sparse-matrix.h"
#include <iostream>

using namespace std;
using namespace kashyap;

int main() {
  matrix<int> m(4, 0);

  m(0, 0) = 1;
  m(1, 3) = 1;
  cerr << m(0, 0) << endl;
  cerr << m(1, 3) << endl;
  cerr << m(0, 2) << endl;

  return 0;
}
