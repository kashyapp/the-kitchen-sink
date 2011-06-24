#include <iostream>
#include <memory>
using namespace std;

class B{
	public:
		B(){
			cout << "B\n";
		}
		~B(){
			cout << "B die\n";
		}
};

class A: public B{
	public:
		A(){
			cout << "A\n";
		}
		~A(){
			cout << "A die\n";
		}
};

class BV{
	public:
		BV(){
			cout << "BV\n";
		}
		virtual ~BV(){
			cout << "BV die\n";
		}
};

class AV: public BV{
	public:
		AV(){
			cout << "AV\n";
		}
		virtual ~AV(){
			cout << "AV die\n";
		}
};

int main(){
	A a;
	auto_ptr<B> pb(new A);
	AV av;
	auto_ptr<BV> pbv(new AV);
	return 0;
}
