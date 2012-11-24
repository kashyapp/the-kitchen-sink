#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <utility>

using namespace std;

void updatemax(int &len_max, vector<char> &str_curr, vector<char> &str_max) {
  int len_curr = str_curr.size();
  if (len_curr > len_max) {
    len_max = len_curr;
    swap(str_curr, str_max);
    str_curr.clear();
  }
}

int main() {
  int len_max = 0;
  vector<char> str_max;

  set<char> c_set;
  vector<char> str_curr;

  int len_prev = 0;
  char c_prev = '\0';

  char c;
  while(cin >> c){
    c_set.insert(c);

    if (c_set.size() > 2) {
      updatemax(len_max, str_curr, str_max);

      c_set.clear(); c_set.insert(c); c_set.insert(c_prev);
      str_curr.clear(); str_curr.resize(len_prev, c_prev);
    }

    str_curr.push_back(c);

    if (c_prev != c) {
      len_prev = 1;
      c_prev = c;
    } else {
      len_prev++;
    }
  }

  updatemax(len_max, str_curr, str_max);

  cout << len_max << endl;
  for(int i = 0; i < str_max.size(); i++) {
    cout << str_max[i];
  }
  cout << endl;

  return 0;
}
