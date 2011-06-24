#include <iostream>
#include <vector>

using namespace std;

int golomb(unsigned int n) {
    vector<unsigned int> v;
    v.reserve(680000);

    v.push_back(0);
    v.push_back(1);
    v.push_back(3);

    switch (n) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
    }

    int j = 2;
    int i;

    for(i = 3; v.back() < n; ++i) {
        if (v[j] < i) {
            //cout << "moving j from " << j << " "  << v[j] << " " << i << endl;
            ++j;
        }
        v.push_back(v.back() + j);
        //cout << i << " " << v.back() << endl;
    }

    return i - 1;
}

int main() {
    unsigned int i;
    while (cin >> i && i != 0) {
        cout << golomb(i) << endl;
    }
}
