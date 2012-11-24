#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>

using namespace std;

void updatemax(int *len_max, const list<char> &str_curr, vector<char> *str_max) {
  int len_curr = str_curr.size();
  if (len_curr > *len_max) {
    *len_max = len_curr;
    str_max->clear();
    str_max->resize(str_curr.size());
    copy(str_curr.begin(), str_curr.end(), str_max->begin());
  }
}

int main() {
  int len_max = 0;
  vector<char> str_max;

  set<char> c_set;

  char c_prev = '\0';

  list<char> str_curr;
  list<char>::iterator iter_prev, iter_curr = str_curr.begin();

  char c;
  while(cin >> c){
    c_set.insert(c);

    if (c_set.size() > 2) {
      updatemax(&len_max, str_curr, &str_max);

      c_set.clear(); c_set.insert(c); c_set.insert(c_prev);
      str_curr.erase(str_curr.begin(), iter_prev);
    }

    str_curr.push_back(c);
    iter_curr++;

    if (c_prev != c) {
      c_prev = c;
      iter_prev = iter_curr;
    }

  }

  updatemax(&len_max, str_curr, &str_max);

  cout << len_max << endl;
  for(int i = 0; i < str_max.size(); i++) {
    cout << str_max[i];
  }
  cout << endl;

  return 0;
}
