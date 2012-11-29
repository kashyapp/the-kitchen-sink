#include <iostream>
#include <vector>
#include <ext/hash_map>
#include <string>
#include <sstream>
using namespace std;
using namespace __gnu_cxx;

string toDecimal(int num, int den) {
  stringstream sbuf;

  sbuf << num/den << '.'; // print whole part

  hash_map<int, int> remQ;
  vector<int> q;

  num %= den;
  do {
    remQ[num] = q.size();

    num *= 10;

    q.push_back(num / den);
    num %= den;

  } while(remQ.find(num) == remQ.end());

  int repeatStart = remQ[num];

  for (int i = 0; i < q.size(); ++i) { // print decimal part
    if (i == repeatStart) {
      sbuf << '(';
    }
    sbuf << q[i];
  }
  sbuf << ')';

  return sbuf.str();
}

int main() {
  int m, n;
  while (cin >> m >> n) {
    cout << toDecimal(m, n) << endl;
  }
  return 0;
}
