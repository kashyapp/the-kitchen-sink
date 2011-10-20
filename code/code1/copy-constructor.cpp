#include <iostream>
using namespace std;

static int i = 0;
static int j = 0;

class Foo {
    string s;
    int mi;
    public:
    Foo(const Foo &);
    Foo(string _s);
    friend ostream& operator<<(ostream& o, const Foo &foo);
};


Foo::Foo(string _s) : s(_s), mi(0) {
    cerr << "yell" << endl;
    i++;
}

Foo::Foo(const Foo &that) : s(that.s), mi(that.mi + 1) {
    cerr << "help" << endl;
    j++;
}


Foo test() {
    Foo poo("kashyap");
    cout << poo << endl;
    return poo;
}

ostream& operator<<(ostream& o, const Foo &foo) {
    cout << (void*) &foo << " " << foo.s << " " << foo.mi;
    return o;
}

int main() {
    Foo pee = test();
    cout << i << " " << j << endl;
    cout << pee << endl;
    return 0;
}

