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

inline int max(int a, int b) {
  return a > b ? a : b;
}

int real_solve(vector<int>::iterator start, vector<int>::iterator end, int k) {
  calls++;
  if (start + 1 == end) {
    return *start;
  }

  int days;
  bool days_is_set = false;

  if (k > 0) {
    int if_slept = max(*start, real_solve(start+1, end, k-1));
    days = if_slept;
    days_is_set = true;
  }

  {
    *(start+1) += *(start);
    int if_not_slept = real_solve(start+1, end, k);
    if (!days_is_set || if_not_slept < days) {
      days = if_not_slept;
    }

    *(start+1) -= *(start);
  }

  return days;
}

int solve(vector<int> legs, int n, int k) {
  timeval t0, t1;
  calls = 0;

  gettimeofday(&t0, NULL);
  int result = real_solve(legs.begin(), legs.end(), k);
  gettimeofday(&t1, NULL);

  cerr << (t1.tv_sec - t0.tv_sec) * 1000 + (t1.tv_usec - t0.tv_usec) / 1000 << n << " " << k << " " << calls << endl;
  return result;
}

