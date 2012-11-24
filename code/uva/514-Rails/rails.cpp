#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void real_solve(int n, vector<int> &target) {
  stack<int> station;

  int incoming = 1;
  for(vector<int>::iterator i = target.begin(); i != target.end(); ++i) {
    int coach = *i;
    while (incoming <= coach) {
      station.push(incoming++);
    }
    if (station.top() == coach) {
      station.pop();
    } else {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
}

void solve(int n) {
  int temp, i;
  vector<int> target(n);
  for(cin >> temp, i = 0; temp > 0; cin >> temp, i = (i+1)%n) {
    target[i] = temp;
    if (i == (n-1)) {
      real_solve(n, target);
    }
  }
}

int main() {
  int n;
  for(cin >> n; n > 0; cin >> n) {
    solve(n);
    cout << endl;
  }
}
