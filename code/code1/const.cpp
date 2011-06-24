#include <iostream>
#include <string>
using namespace std;

void baz(char *s){
	cout << s << endl;
	s[0]='K';
}

void foo(const std::string* s){
	s = new string("kashyap");
}
void bar(std::string* s){
	string &foo = *s;
	foo[2]='a';
}

int main(){
	string f("arun");
	string g("hell");
	const string k("fubar");

	foo(&f);
	cout<<f<<endl;
	bar(&f);
	cout<<f<<endl;
	foo(&g);
	cout<<g<<endl;
	bar(&g);
	cout<<g<<endl;
	cout<<k<<endl;
	baz((char *)k.c_str());
	cout<<k<<endl;
	
	return 0;
}
