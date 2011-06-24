#include <iostream>
using namespace std;

class Foo{
	private:
		Foo(const Foo&);
	public:
		Foo(){
		}
};

Foo& bar(){
	Foo *a = new Foo;
	return *a;
}

int main(){
	Foo poo;
	poo= bar();
	return 0;
}
