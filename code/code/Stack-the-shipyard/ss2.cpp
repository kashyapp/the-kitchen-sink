#include <iostream>
#include <vector>

using namespace std;

struct box {
  int x, y, z;
  box(int _x, int _y, int _z) {
    z = _z;
    x = max(_x, _y);
    y = min(_x, _y);
  }

  bool operator< (const box &r) const {
    if (x == r.x) return y < r.y;
    return x < r.x;
  }

  bool operator>> (const box &r) const {
    return x > r.x && y > r.y;
  }
};

int solve(vector<box> &boxes) {
  int n = boxes.size();
  vector<int> heights(n, 0);

  int maxheight = heights[0] = boxes[0].z;

  for(int i = 1; i < n; ++i) {
    int zcur = boxes[i].z;
    int zmax = zcur;
    for(int j = 0; j < i; ++j) {
      if (boxes[i] >> boxes[j]) {
        zmax = max(zmax, zcur + heights[j]);
      }
    }
    heights[i] = zmax;
    maxheight = max(zmax, maxheight);
  }

  return maxheight;
}

int main() {
  int n;
  cin >> n;
  vector<box> boxes;

  for(int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    boxes.push_back(box(x, y, z));
    boxes.push_back(box(x, z, y));
    boxes.push_back(box(y, z, x));
  }

  sort(boxes.begin(), boxes.end());

  cout << "The maximum possible height of stack is " << solve(boxes) << endl;

  return 0;
}
