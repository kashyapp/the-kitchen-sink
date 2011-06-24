#include <iostream>
#include <set>
using namespace std;

void swap(char *a, char *b){
	char c=*a;
	*a=*b;
	*b=c;
}

void purm(char *s, int i){
#ifdef DEBUG
	cout << ".";
#endif
	if(i==0)
		cout << s << endl;
	for(int j=i; j >= 0; --j){
		swap(&s[i], &s[j]);
		purm(s,i-1);
		swap(&s[i], &s[j]);
	}
}


bool foo(bool &done){
	if(done)
		return false;
	else
		done = true;
	return true;
}

void dparm(char *s, int i){
#ifdef DEBUG
	cout << ".";
#endif
	bool done=false;
	if(i==0)
		cout << s << endl;
	for(int j=0; j <= i; ++j){
		if(i==j || s[i]!=s[j] || foo(done)){
			swap(&s[i], &s[j]);
			dparm(s,i-1);
			swap(&s[i], &s[j]);
		}
	}
}

void parm(char *s, int i){
#ifdef DEBUG
	cout << ".";
#endif
	if(i==0)
		cout << s << endl;
	for(int j=0; j <= i; ++j){
		swap(&s[i], &s[j]);
		parm(s,i-1);
		swap(&s[i], &s[j]);
	}
}

void perm(char *s, int i){
#ifdef DEBUG
	cout << ".";
#endif
	if(s[i]=='\0')
		cout << s << endl;
	for(int j=i; s[j]!='\0'; ++j){
		swap(&s[i], &s[j]);
		perm(s,i+1);
		swap(&s[i], &s[j]);
	}
}

int main(int argc, char **argv){
	assert(argc>1 || !"one argument please");
	//cout << "\ninput : " << argv[1]<<endl;
	//perm(argv[1],0);
	//cout << "\ninput : " << argv[1]<<endl;
	//parm(argv[1],strlen(argv[1])-1);
	//cout << "\ninput : " << argv[1]<<endl;
	//purm(argv[1],strlen(argv[1])-1);
	cout << "\ninput : " << argv[1]<<endl;
	dparm(argv[1],strlen(argv[1])-1);
	return 0;
}
