#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

#define N 30
#define M 100

int main(int argc, char **argv) {
  assert(argc == 3);

  int seed = atoi(argv[2]);
  int n = atoi(argv[1]);

  srand(seed);
  cout << rand()%M << " ";
  while(n--) {
    cout << (rand()%3 ? '+' : '-') << " " << rand()%M << " ";
  }
  cout << endl;

  return 0;
}
