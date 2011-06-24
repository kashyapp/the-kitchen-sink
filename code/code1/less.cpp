#include <bits/stl_function.h>
#include <algorithm>

struct Foo{
	int i;
};

struct Bar{
	int k;
};

namespace std{
	template<> struct less<Foo> : Bar{
		bool operator()(const Foo &a, const Foo &b) const{
			return a.i < b.i;
		}
	};
}

int main(){
	return 0;
}
