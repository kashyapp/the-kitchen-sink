#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <functional>
#include <list>

using namespace std;

struct Comparo : public binary_function<int, int, bool>{
  const vector<int> lookup;
  Comparo(const vector<int> &_l) : lookup(_l) {}
  bool operator()(int l, int r) const {
    return lookup[l] > lookup[r];
  }
};

template<typename T>
int lis2(vector<T> input) {
  vector<int> indexed;
  vector<int> successors(input.size(), -1);

  Comparo comparo(input);

  indexed.push_back(input.size() - 1);

  for(int i = input.size()-2; i >= 0; --i) {
    T current = input[i];

    if (current < input[indexed.back()]) {
      successors[i] = indexed.back();
      indexed.push_back(i);
    } else {
      typename vector<T>::iterator pos = lower_bound(indexed.begin(), indexed.end(), i, comparo);

      successors[i] = successors[*pos];
      *pos = i;
    }
  }

  for (int start = indexed.back(); start >= 0; start = successors[start]) {
    cout << input[start] << " ";
  }
  cout << endl;

  return indexed.size();
}

int main() {
  int n;
  vector<int> v;
  while(cin >> n) {
    v.push_back(n);
  }
  cout << lis2(v) << endl;
  return 0;
}
