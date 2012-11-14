#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cctype>

using namespace std;

enum RESULT {EMPTY, TRUE, FALSE};

RESULT solve(int target) {
  RESULT result = FALSE;

  char c;

  cin >> c; // ignore this should always be '('
  assert(c == '(');

  cin >> c;
  cin.putback(c);

  if (c==')') {
    result = EMPTY;
  } else {

    int root;
    cin >> root;

    target -= root;

    RESULT left = solve(target);
    RESULT right = solve(target);

    if (target == 0
        && left == EMPTY
        && right == EMPTY) {

      result = TRUE;
    }

    if (left == TRUE || right == TRUE) {
      result = TRUE;
    }

  }

  cin >> c; // this should always be ')'
  assert(c == ')');
  return result;
}

int main() {
  int target;
  while (cin >> target) {
    RESULT decision = solve(target);
    cout << (decision == TRUE ? "yes" : "no") << endl;
  }
  return 0;
}
