#include <iostream>
using namespace std;

typedef char foo_t[10];

int main(){
    int *i;
    cout << i << endl;
    i = NULL;
    cout << i << endl;
    i = new int(10);
    cout << i << endl;
    free(i);
    cout << i << endl;

    char *a = "fubar";
    cout << a << endl;
    a = "kashyap";
    cout << a << endl;

    foo_t bar;
    cout << bar << endl;

    return 0;
}
