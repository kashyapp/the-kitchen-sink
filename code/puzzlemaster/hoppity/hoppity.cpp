#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void hoppity(int m) {
    for (int n = 1; n <= m; n++) {
        cerr << n%3 << " " << n%5 << endl;
        if (! (n % 15) ) {
            cout << "Hop" << endl;
        } else if (! (n % 3) ) {
            cout << "Hoppity" << endl;
        } else if (! (n % 5) ) {
            cout << "Hophop" << endl;
        } 
    }
}

int main(int argc, char **argv) {

    if (argc == 1) {
        return 1;
    }

    const char *filename = argv[1];

    ifstream in(filename);

    if (!in.good()) {
        return 1;
    }

    int n;
    in >> n;

    hoppity(n);
    return 0;
}
