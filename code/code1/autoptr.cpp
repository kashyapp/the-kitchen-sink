#include <memory>
#include <iostream>
#include <string>
using namespace std;

class foo{
    foo();
    foo(const foo&);
    foo& operator =(const foo&);
    string s_;
    public:
        void print(){
            cout << s_ << endl;
        }
        foo(string s): s_(s){
            cerr << "cry: " << s_ << '\n';
        }
        ~foo(){
            cerr << "die: " << s_ << '\n';
        }
};

void bar(auto_ptr<foo> p){
	cout << "in bar" << endl;
	p->print();
	cout << "exit bar" << endl;
}

int main(){
    foo Two("bobby");
    Two.print();
    int(2);
    auto_ptr<foo> pOne(new foo("bunny"));
    pOne->print();
    pOne = pOne;
    pOne->print();
    bar(pOne);
    pOne->print();
    cerr<<"nice\n";
    return 0;
}
