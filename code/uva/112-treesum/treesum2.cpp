#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cctype>

using namespace std;

enum RESULT {EMPTY, TRUE, FALSE};

RESULT solve(istream &in, int target) {
  RESULT result = FALSE;

  char c;

  in >> c; // ignore this should always be '('
  assert(c == '(');

  in >> c;
  in.putback(c);

  if (c==')') {
    result = EMPTY;
  } else {

    int root;
    in >> root;

    target -= root;

    RESULT left = solve(in, target);
    RESULT right = solve(in, target);

    if (target == 0
        && left == EMPTY
        && right == EMPTY) {

      result = TRUE;
    }

    if (left == TRUE || right == TRUE) {
      result = TRUE;
    }

  }

  in >> c; // this should always be ')'
  assert(c == ')');
  return result;
}

int main() {
  int target = 22;
  string s = "(5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))";
  stringstream in(s);
  RESULT decision = solve(in, target);
  cout << (decision == TRUE ? "yes" : "no") << endl;
  return 0;
}
