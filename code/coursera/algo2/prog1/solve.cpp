#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

#define FOR(i, n) for(int i = 0; i < n; ++i)

struct Job {
  int weight;
  int length;
};

struct lessdiff {
  bool operator() (const Job& l, const Job& r) {
    int diff = (l.weight - l.length) - (r.weight - r.length);
    if (diff != 0) return diff > 0;

    return l.weight > r.weight;
  }
};

struct lessratio {
  bool operator() (const Job& l, const Job& r) {
    return l.weight * r.length > r.weight * l.length;
  }
};

int main() {
  int n;
  cin >> n;

  Job jobs[n];
  FOR(i, n) {
    cin >> jobs[i].weight >> jobs[i].length;
  }

  sort(jobs, jobs + n, lessdiff());

  long result = 0;
  long clock = 0;
  FOR(i, n) {
    Job j = jobs[i];
    clock += j.length;
    result += clock * j.weight;

    cerr << j.weight << " " << j.length << " " << clock << " " << clock * j.weight << " " << result << endl;
  }

  cout << result << endl;

  return 0;
}
