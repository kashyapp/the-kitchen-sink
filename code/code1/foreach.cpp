#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

struct reverser: public unary_function<string,void>{
	int i;
	int j;
	string foo;
	void operator()(string &s){
		j++;
		s+=" : ";
		foo+=s;
		cout << s;
	}
	/*
	reverser(){
		i=0;
		j=0;
		cout << " !!self born!! " << endl;
	}
	reverser(const reverser& r){
		i=r.i+1;
		j=r.j;
		foo=r.foo;
		cout << " !!copy born!! " << i << " " << foo << endl;
	}
	*/
	~reverser(){
		cout << " !!die!! " << foo << endl;
	}
	/*
	reverser& operator=(const reverser& r){
		j = r.j;
		foo = r.foo;
		cout << " !! assign !! " << i << " " << foo << endl;
		return *this;
	}
	*/
};

int main(){
	vector<string> vs;
	reverser r;
	string s;
	while(cin>>s){
		vs.push_back(s);
	}
	copy(vs.begin(),vs.end(),ostream_iterator<string>(cout,","));
	cout<<endl;
	reverser rr(for_each(vs.begin(), vs.end(), r));
	cout<<endl;
	copy(vs.begin(),vs.end(),ostream_iterator<string>(cout,";"));
	cout<<endl;
	cout<<"r.foo  " << r.foo<<endl;
	cout<<"rr.foo " << rr.foo<<endl;
	return 0;
}
