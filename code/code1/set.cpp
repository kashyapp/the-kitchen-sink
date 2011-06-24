#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
	string s;
	set<string> S;
	while(cin>>s){
		if(S.find(s)!=S.end())
			cout << " already there\n";
		else{
			S.insert(s);
			cout << " added to set\n";
		}
	}
	cout<<"outputting our set: \n";
	copy(S.begin(), S.end(), ostream_iterator<string>(cout, ", "));
	cout<<endl;
	return 0;
}
