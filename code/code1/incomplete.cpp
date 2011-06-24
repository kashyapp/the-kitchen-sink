#include <vector>
#include <utility>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>
using namespace std;

class foo{
	vector<foo> bar;
	list<foo> baz;
	set<foo> x;
	map<int,foo> y;
	public:
	void f();
};

void foo::f(){
	foo a;
	bar.push_back(a);
	y[0]=a;
}


struct ltstr: public binary_function<char *,char *,bool>{
	bool operator()(char *a, char *b){
		return strcmp(a,b) < 0;
	}
};

int main(){
	foo f;
	char *boo[]={"zab","aab","aaac","ad"};
	set<char *,ltstr> ab(boo,boo+4);
	copy(ab.begin(), ab.end(), ostream_iterator<const char*>(cout, " "));   
	cout << endl;
	return 0;
}
