#include <string>
#include <iostream>
#include <cassert>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

void swap(char *a, char *b){
    char c;
    c=*a;
    *a=*b;
    *b=c;
}

void permutations(char *s,int p){
    if(p==0)
        cout<<s<<endl;
    for(int i=0; i < p; ++i){
        swap(s+i,s+p-1);
        permutations(s,p-1);
        swap(s+i,s+p-1);
    }
}

map<int,set<char> > doneMap;
void dpermutations(char *s,int p){
	if(p==0)
		cout<<s<<endl;
	set<char> &done = doneMap[p];
	for(int i=0; i < p; ++i){
		if(done.find(s[i]) == done.end()){
			done.insert(s[i]);
			swap(s+i,s+p-1);
			dpermutations(s,p-1);
			swap(s+i,s+p-1);
		}
    }
	done.clear();
}


void dpermutations2(char *s,int p){
	if(s[p]=='\0')
		cout<<s<<endl;
	set<char> &done = doneMap[p];
	for(int i=p; s[i]!='\0' ; ++i){
		if(done.find(s[i]) == done.end()){
			done.insert(s[i]);
			swap(s+i,s+p);
			dpermutations2(s,p+1);
			swap(s+i,s+p);
		}
    }
	done.clear();
}


void getPermutations(char * s,unsigned int nxtWorkChar) {

    if(s[nxtWorkChar] == '\0') {
		cout << s << endl;
        return;
    }

	unsigned int i,j;

    getPermutations(s,nxtWorkChar + 1);
    for(i = nxtWorkChar ; i > 0 && s[i] != s[i - 1]; i--) {
        swap(s[i],s[i-1]);
        getPermutations(s,nxtWorkChar + 1);
    }//for
    
    for(j = i ; j < nxtWorkChar ; j++)    swap(s[j],s[j + 1]);

}
int main(int argc, char **argv){
	assert(argc>1 || !"we need an argument");
	cout << "plain old permutations\n";
    permutations(argv[1],strlen(argv[1]));
	
	cout << "duplicate removal included\n";
	getPermutations(argv[1],0);
	cout << "duplicate removal included mine \n";
	dpermutations(argv[1],strlen(argv[1]));
	cout << "duplicate removal included mine2 \n";
	dpermutations2(argv[1],0);

	return 0;
}
