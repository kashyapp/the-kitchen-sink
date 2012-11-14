#include <iostream>
#include <vector>

using namespace std;

#define INF 999999999
#define BLANK -1
#define GREY -2

void slurp(vector<int> &head, vector<int> &tail) {
  int num;
  cin >> num;
  while(num--) {
    int h, t;
    cin >> h >> t;
    head.push_back(h);
    tail.push_back(t);
  }
}

int f(int l, int curr, vector<int> &board, vector<int> &hops) {
  if (hops[curr] == GREY) return INF;
  if (hops[curr] != INF) return hops[curr];

  //cerr << "f(" << curr << ")"<< endl;

  int result;
  hops[curr] = GREY;

  if (board[curr] != BLANK) {
    result = f(l, board[curr], board, hops);
  } else {
    int min = INF;
    for(int i=1; i<=6 && curr + i < l; ++i) {
      int trial = f(l, curr + i, board, hops);
      if(trial < min) {
        min = trial;
      }
    }
    result = 1 + min;
  }

  hops[curr] = result;
  //cerr << curr << " " << result << endl;

  return result;
}

int solve(vector<int> &board) {
  int l = board.size();

  vector<int> hops(l, INF);
  hops[l-1] = 0;

  return f(l, 0, board, hops);
}

int main() {
  int n;
  cin >> n;

  vector<int> start, end;
  slurp(start, end);
  slurp(start, end);
  //slurp(end, start);

  vector<int> board(n * n, BLANK);

  for(int i=0; i < start.size(); ++i) {
    board[start[i]] = end[i];
    //cerr << start[i] << " " << board[start[i]] << endl;
  }

  cout << solve(board) << endl;

  return 0;
}
