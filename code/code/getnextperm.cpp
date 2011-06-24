#include <iostream>
#include <cstring>
using namespace std;

bool get_next_permutation(char *s) {
    bool found = false;
    return found;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        cerr << "Needs an argument" << endl;
        return 1;
    }
    char *s = strdup(argv[1]);
    while (get_next_permutation(s)) {
        cout << s << endl;
    }
    return 0;
}


