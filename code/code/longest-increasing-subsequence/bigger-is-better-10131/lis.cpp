#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <functional>
#include <list>

using namespace std;

template<typename T>
struct Comparo : public binary_function<int, int, bool>{
  const vector<T> lookup;
  Comparo(const vector<T> &_l) : lookup(_l) {}
  bool operator()(int l, int r) const {
    return lookup[l] > lookup[r];
  }
};

template<typename T>
int lis2(vector<T> input) {
  vector<int> indexed;
  vector<int> successors(input.size(), -1);

  Comparo<T> comparo(input);

  indexed.push_back(input.size() - 1);

  for(int i = input.size()-2; i >= 0; --i) {
    T current = input[i];

    if (current < input[indexed.back()]) {
      successors[i] = indexed.back();
      indexed.push_back(i);
    } else {
      typename vector<int>::iterator pos = lower_bound(indexed.begin(), indexed.end(), i, comparo);

      successors[i] = successors[*pos];
      *pos = i;
    }
  }

  for (int start = indexed.back(); start >= 0; start = successors[start]) {
    cout << start << " ";
  }
  cout << endl;

  return indexed.size();
}

int main() {
  int m, n;
  vector<pair<int, int> > v;
  while(cin >> m >> n) {
    v.push_back(make_pair(m, 0));
  }
  cout << lis2(v) << endl;
  return 0;
}
