#include <iostream>
#include <map>
#include <utility>

using namespace std;
int main() {
  int n;
  cin >> n;

  map<int, int> data;
  for (int i = 0; i < n; ++i) {
    int day;
    int value;
    cin >> day >> value;
    data[day] = value;
  }

  int start, end;
  cin >> start >> end;

  int lastvalue;
  map<int, long> freq;
  for (map<int, int>::iterator i = data.begin();
      i != data.end();
      ++i) {
    cerr << i->first << " -> " << i->second << endl;

    if (i->first > start) {
      if (i->first < end) {
        freq[lastvalue] += i->first - start;

        lastvalue = i->second;
        start = i->first;
      } else {
        freq[lastvalue] += end - start;
        start = end;
        break;
      }
    } else {
      lastvalue = i->second;
    }
  }
  if (start < end) {
    freq[lastvalue] += end - start;
  }

  for (map<int, long>::iterator i = freq.begin();
      i != freq.end();
      ++i) {
    cerr << i->first << " : " << i->second << endl;
  }

  return 0;
}
