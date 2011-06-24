#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <sys/times.h>
#include <unistd.h>
using namespace std;

#define NEXT(i,n) ((2*(i))%((n)-1))

bool check(long i, long n, long &count){
    long j=i;
    while((j=NEXT(j,n))>i)
        count++;
    return (j<i)?true:false;
}

long  cycleMerge(vector<long> &A){
    long count=0;
    long m = A.size();
    for(long i=0;i<m;++i){
        long j;
        if(check(i,m,count))
            continue;
        for(j = NEXT(i,m);
                j!= i;
                j = NEXT(j,m)){
            swap(A[i],A[j]);
            count++;
        }
        swap(A[i],A[j]);
        count++;
    }
    return count;
}

long divMerge(vector<long> &A){
	return cycleMerge(A);
}

int main(long argc, char **argv){
    assert(argc>=2 || !"one int arg please");
    long n=atoi(argv[1]);
    assert(n || !"one int arg please");
	long m=n*2;
	vector<long> A(m);
	clock_t t0,t1;
	long count;


	{
		for(long i=0;i<m;++i) A[i]=i;
		t0 = times(NULL);
		count = cycleMerge(A);
		t1 = times(NULL);
		copy(A.begin(),A.end(),ostream_iterator<long>(cerr,", "));
	cerr<<endl;
		cout << m << "\t" << count << "\t" << t1-t0 << "\t" << sysconf(_SC_CLK_TCK) << endl;
	}

	{
		for(long i=0;i<m;++i) A[i]=i;
		t0 = times(NULL);
		count = divMerge(A);
		t1 = times(NULL);
//		copy(A.begin(),A.end(),ostream_iterator<long>(cerr,", "));
//		cerr<<endl;
		cout << m << "\t" << count << "\t" << t1-t0 << "\t" << sysconf(_SC_CLK_TCK) << endl;
	}

	return 0;
}

