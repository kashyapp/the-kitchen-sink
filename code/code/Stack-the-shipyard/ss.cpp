#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <map>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

struct box {
  int x, y, z;
  box(int _x, int _y, int _z) {
    z = _z;
    x = max(_x, _y);
    y = min(_x, _y);
  }
  void print() {
    cout << x << " " << y << " " << z << endl;
  }
};

typedef vector<box>::iterator IT;
map<pair<IT, IT>, int> cache;

template<typename I>
int solve(I base, I begin, I end) {
  if (begin == end) return 0;

  pair<IT, IT> cache_key = make_pair(base, begin);
  if (cache.find(cache_key) != cache.end()) return cache[cache_key];

  int with = 0;
  if (*base >> *begin) {
    with = (*begin).z + solve(begin, begin + 1, end);
  }
  int without = solve(base, begin + 1, end);

  return (cache[cache_key] = max(with, without));
}

bool operator>> (const box &l, const box &r) {
  return l.x > r.x && l.y > r.y;
}

bool operator< (const box &l, const box &r) {
  if (l.x == r.x) return l.y > r.y;
  return l.x > r.x;
}

int main() {
  int n;
  cin >> n;
  vector<box> boxes;
  boxes.push_back(box(INT_MAX, INT_MAX, 0));

  for(int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    boxes.push_back(box(x, y, z));
    boxes.push_back(box(x, z, y));
    boxes.push_back(box(y, z, x));
  }
  sort(boxes.begin(), boxes.end());

  cout << "The maximum possible height of stack is " << solve(boxes.begin(), boxes.begin(), boxes.end()) << endl;

  return 0;
}
