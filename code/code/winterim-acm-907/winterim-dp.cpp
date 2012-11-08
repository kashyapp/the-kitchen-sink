#include <iostream>
#include <vector>
#include <sys/time.h>
#include <cstdio>

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

struct cell {
  int dist;
  int max;
};
cell table[N_MAX+1][K_MAX+1];

int real_solve(vector<int> legs, int n, int k) {
  for(int i=0; i<=k; ++i) {
    table[0][i].dist = legs[0];
    table[0][i].max = legs[0];
  }
  for(int j=1; j <= n; j++) {
    table[j][0].dist = legs[j] + table[j-1][0].dist;
    table[j][0].max  = legs[j] + table[j-1][0].max;
  }

  for(int j=1; j<=n; ++j) {
    for(int i=1; i<=k; ++i) {
      cell contnu  = table[j-1][i];
      cell sleep = table[j-1][i-1];
      int leg = legs[j];

      int skip_max = max(contnu.dist + leg, contnu.max);
      int sleep_max = max(leg, sleep.max);

      if (sleep_max > skip_max) {
        table[j][i].max = skip_max;
        table[j][i].dist = leg + contnu.dist;
      } else {
        table[j][i].max = sleep_max;
        table[j][i].dist = leg;
      }
      printf("[%4d %4d] ",table[j][i].max, table[j][i].dist); 
    }
    printf("\n");
  }

  return table[n][k].max;
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

