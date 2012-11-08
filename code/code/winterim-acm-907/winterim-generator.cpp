#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <tr1/cstdint>

using namespace std;

#define LEG_MAX (INT_MAX / 200)
#define LEG_MIN 10

int main(int argc, char **argv) {
  assert(argc == 3);

  int n = atoi(argv[1]);
  int k = atoi(argv[2]);

  cout << n << " " <<  k << endl;
  for(int i = 0; i <= n; ++i) {
    int r = rand();
    cout << LEG_MIN + (r % (LEG_MAX - LEG_MIN)) << endl;
  }

  return 0;
}
