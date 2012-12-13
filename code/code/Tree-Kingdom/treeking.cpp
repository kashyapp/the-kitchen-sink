#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool check(int *trees, int n, int spell) {
  int prev = 0;
  int i;
  for(i = 0; i < n; ++i) {
    int current = trees[i];
    if (current > prev) {

      prev = max(current - spell, prev + 1);

    } else if (prev + 1 - current > spell) {

      break;

    } else {
      
      prev = prev + 1;

    }

  }
  return i == n;
}

int main() {
  int n;
  cin >> n;

  int *trees = new int[n];

  for(int i = 0; i < n; ++i) {
    cin >> trees[i];
  }

  int result = -1;
  for(int i = 0; result == -1; ++i) {
    if (check(trees, n, i)) result = i;
  }

  cout << result << endl;

  return 0;
}
