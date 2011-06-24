#include <iostream>
#include <cstdlib>
using namespace std;

class bar;

class foo{
	public:
		static bar a;
	private:
		static bar b;
};

class bar{
	public:
	bar(int i):_i(i){
		cerr << "creating bar " << _i << "\n";
	}
	virtual ~bar(){
		cerr << "dying bar " << _i << "\n";
	}
	static int plus(int i){
		return _s += i;
	}
	int getI() const{
		return _i;
	}
	private:
	bar();
	bar(const bar&);
	bar& operator=(const bar&);
	int _i;
	static int _s;
};

bar foo::a(100);
bar foo::b(200);
int bar::_s = 5;


void burr(){
	int pip(){
		return rand(NULL);
	}
	class ping{
		public:
			int k;
	};
	bar test(pip());
	cout << bar::plus(test.getI()) << '\n';
}

int main(){
	foo foof;
	burr();
	burr();
	return 0;
}
	

