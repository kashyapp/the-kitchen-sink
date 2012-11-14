#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int main() {
  int nTest;
  cin >> nTest;

  while(nTest--) {
    int n;
    cin >> n;

    int position = 0;
    int steps[101];

    char line[15];
    char *s = &line[0];

    for(int i=1; i<=n; ++i) {
      int step = 0;

      cin >> s;
      switch(s[0]) {
        case 'L': // LEFT
          step = -1;
          break;
        case 'R': // RIGHT
          step = 1;
          break;
        case 'S': // SAME AS xxx
          cin >> s;
          int lookup;
          cin >> lookup;
          step = steps[lookup];
          break;
      }

      steps[i] = step;
      position += step;
    }

    cout << position << endl;
  }

  return 0;
}
