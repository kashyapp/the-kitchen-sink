#include <iostream>
using namespace std;

class Foo{
	private:
	int i;
	public:
	Foo& operator=(const Foo& t){
		this->i=t.i;
		cout << "assign\n";
	}
	Foo(){
		cout << "default\n";
	}
	Foo(const int &k) :i(k){
		cout << "int constr\n";
	}
};

Foo::Foo(const Foo &f) throw()
	: i(2*f.i){
	cout << "copy constr\n";
}

void test() throw();

class Bar{
	Foo f;
	public:
	Bar(){
		cout << "bar default\n";
	}
	/*
	Bar(const Bar &g) : f(g.f){
		cout << "bar copy constr \n";
	}*/
};

class Barr{
	Foo f;
	public:
	Barr(){
		cout << "barr default\n";
	}
	Barr(const Barr &g){
		f = g.f;
		cout << "barr copy constr \n";
	}
};


int main(){
	Foo a;
	Foo b(1);
	Foo c = 2;
	Foo d = Foo(3);
	Foo e = d;

	
	return 0;
}
