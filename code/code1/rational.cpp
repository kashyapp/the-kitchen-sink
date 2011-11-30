#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

void print(vector<int> quotients, int marker) {
    for (int i = 0; i < marker; ++i) {
        cout << quotients[i];
    }
    cout << '(';
    for (int i = marker; i < quotients.size(); ++i) {
        cout << quotients[i];
    }
    cout << ')' << endl;
}


void divide(int p, int q) {
    int quotient = p / q;
    cout << quotient << '.';

    vector<int> quotients;
    map<int, int> remainders;
    int r = p % q;
    p = r;

    bool terminating = true;
    do {
        remainders[r] = quotients.size();

        p = r * 10;
        quotient = p / q;
        r = p % q;

        quotients.push_back(quotient);

        if (remainders.find(r) != remainders.end()) {
            int found = remainders[r];
            print(quotients, found);
            terminating = false;
            break;
        }

    } while (r);

    if (terminating) {
        copy(quotients.begin(), quotients.end(), ostream_iterator<int>(cout, "")); 
        cout << endl;
    }

}

int main() {
    int p, q;
    cin >> p >> q;
    divide(p, q);
    return 0;
}
