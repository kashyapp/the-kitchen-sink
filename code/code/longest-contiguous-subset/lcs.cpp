#include <tr1/unordered_map>
#include <ext/hash_map>
#include <iostream>

using namespace std;
using namespace std::tr1;
using namespace __gnu_cxx;

template <class I>
int lcs(I begin, I end) {
  int max = 0;

  hash_map<int, int> cons_len;

  for(I i = begin; i != end; i++) {
    int current = *i;

    int prev_len = cons_len[current - 1];
    int next_len = cons_len[current + 1];

    int len = prev_len + 1 + next_len;

    cons_len[current] 
      = cons_len[current - prev_len] 
      = cons_len[current + next_len] 
      = len;

    if (len > max) max = len;
  }

  return max;
}

int main() {
  int data[] = { 5, 12, 14, 4, 11, 1, 17, 19, 2, 13, 16, 15, 18, 3};
  int len = sizeof(data)/sizeof(int);

  int *begin = &data[0];
  int *end = begin + len;

  int result = lcs(begin, end);
  cout << result << endl;

  return 0;
}
