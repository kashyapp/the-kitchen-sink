#include <iostream>
#include <string>
using namespace std;

int main(){
	string foo;
	cin>>foo;
	const char* bar;
	bar = foo.c_str();
	cout<<bar<<endl;
	return 0;
}
