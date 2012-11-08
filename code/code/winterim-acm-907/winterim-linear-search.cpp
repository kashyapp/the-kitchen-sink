#include <iostream>
#include <vector>
#include <sys/time.h>

using namespace std;

#define N_MAX 600
#define K_MAX 300

int calls;

int solve(vector<int> legs, int n, int k);

int main() {
  int N, K;

  while(cin >> N >> K) {
    vector<int> legs;

    for(int i = 0; i <=N; ++i) {
      int d;
      cin >> d;
      legs.push_back(d);
    }

    cout << solve(legs, N, K) << endl;
  }

  return 0;
}

inline int min(int a, int b) {
  return a < b ? a : b;
}

inline int max(int a, int b) {
  return a > b ? a : b;
}

bool check(vector<int> legs, int test, int n, int k, bool is_print) {
  int current=0;
  for (int i=0; i <= n && k >= 0; ++i) {
    if ((current + legs[i]) <= test) {
      current += legs[i];
    } else {
      if (is_print) {
        //cerr << current << " " << i << endl;
      }
      k--;
      current=legs[i];
    }
  }

  return k >= 0;
}

int real_solve(vector<int> legs, int n, int k) {
  int max_leg = legs[0];
  int total_distance = legs[0];

  for (int i = 1; i <= n; ++i) {
    total_distance += legs[i];
    max_leg = max(max_leg, legs[i]);
  }

  for (int test=max_leg; test <= total_distance; test++) {
    if (check(legs, test, n, k, false)) {
      check(legs, test, n, k, true);
      return test;
    }
  }
  return total_distance;
}

int solve(vector<int> legs, int n, int k) {
  timeval t0, t1;
  calls = 0;

  gettimeofday(&t0, NULL);
  int result = real_solve(legs, n, k);
  gettimeofday(&t1, NULL);

  //cerr << (t1.tv_sec - t0.tv_sec) * 1000 + (t1.tv_usec - t0.tv_usec) / 1000 << n << " " << k << " " << calls << endl;
  return result;
}

