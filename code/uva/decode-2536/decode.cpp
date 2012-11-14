#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int case_id = 1; case_id <= n; ++case_id) {
    cout << "Case " << case_id << ": ";
    string encoded;
    cin >> encoded;
    char c;
    int n;
    bool isset = false;
    for(string::iterator i = encoded.begin(); i != encoded.end(); i++) {
      if (isdigit(*i)) {
        n = (*i - '0') + n * 10;
      } else {
        if (isset) {
          for (int i=0; i<n; ++i) {
            cout << c;
          }
        }
        c = *i;
        n = 0;
        isset = true;
      }
    }
    if (isset) {
      for (int i=0; i<n; ++i) {
        cout << c;
      }
    }
    cout << endl;
  }
  return 0;
}
