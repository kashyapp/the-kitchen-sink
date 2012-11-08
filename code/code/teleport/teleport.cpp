#include <iostream>
#include <queue>
#include <utility>
using namespace std;

void foo(int x, int y, int depth, vector<vector<int> > &data, int m, int n, queue<pair<int, int> > &bfsQueue, queue<int> &dQueue) {
  //cerr << x << " " << y << " " << depth << endl;
  if (x < 0 || x >= m) return;
  if (y < 0 || y >= n) return;
  if (data[x][y] < 0) return;

  dQueue.push(depth + 1);
  bfsQueue.push(make_pair(x, y));
}

int solve(vector<vector<int> > &data, int m, int n) {
  pair<int, int> start;
  pair<int, int> target;

  cin >> start.first >> start.second;
  cin >> target.first >> target.second;

  queue<pair<int, int> > bfsQueue;
  queue<int> dQueue;

  bfsQueue.push(start);
  dQueue.push(0);

  while(!bfsQueue.empty()) {
    pair<int, int> cell = bfsQueue.front(); bfsQueue.pop();
    int depth = dQueue.front(); dQueue.pop();

    if (cell == target) {
      return depth;
    }

    int d = data[cell.first][cell.second];

    if (d < 0) continue;

    //cerr << cell.first << " " << cell.second << " " << d << " " << depth << endl;
    data[cell.first][cell.second] = -1;

    for (int i = 0; i <= d; ++i) {
      foo(cell.first + i, cell.second + d - i, depth, data, m, n, bfsQueue, dQueue);
      foo(cell.first + i, cell.second - d + i, depth, data, m, n, bfsQueue, dQueue);
      foo(cell.first - i, cell.second + d - i, depth, data, m, n, bfsQueue, dQueue);
      foo(cell.first - i, cell.second - d + i, depth, data, m, n, bfsQueue, dQueue);
    }
  }

  return -1;
}

int main() {
  int m, n;
  cin >> m >> n;

  vector<vector<int> > data;

  for (int i = 0; i < m; ++i) {
    vector<int> row;
    for (int j = 0; j < n; ++j) {
      int t;
      cin >> t;
      row.push_back(t);
    }
    data.push_back(row);
  }

  int result = solve(data, m, n);
  if (result < 0) {
    cout << "LET HER GO" << endl;
  } else {
    cout << result << endl;
  }
  return 0;
}
