#include <iostream>
using namespace std;

class Base{
	public:
	static int i;
};

int Base::i;

class A : public Base{
	public:
	static int j; 
};

int A::j;

class B : public Base{
};


int main(){
	Base p;
	A a;
	B b;
	p.i = 10;
	cout << p.i << endl;
	cout << a.i << endl;
	cout << b.i << endl;
	a.i = 11;
	cout << p.i << endl;
	cout << a.i << endl;
	cout << b.i << endl;
	a.j = 12;
	cout << a.j << endl;
	return 0;
}
