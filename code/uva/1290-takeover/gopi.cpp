// File Name   : takeover.cpp
// Author      : Vishwakarma

#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <bitset>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <utility>
#include <cctype>
#include <list>
#include <map>
#include <set>
#include <float.h>
#include <new>
#include <sstream>
#include <complex>
#include <deque>

#define TR(c,i) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++ ) 
#define SWAP(a,b) {typeof(a) T; T=a; a=b; b=T;}
#define FOR(i,a,b) for ( i = a; i <= b; i++ )
#define ROF(i,a,b) for ( i = a; i >= b; i-- )
#define MEM(t,n) ( t * )malloc( (n)*sizeof( t ) )
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort( ALL(v) )
#define MAX(a,b) ((a) >= (b) ? (a) : (b))
#define MIN(a,b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) < (0) ? (a)*(-1) : (a))
#define SET(x,a) memset(x,a,sizeof(x))
#define IN(x,a) x.find(a) != x.end()  
#define SQ(x) (x)*(x)
#define DIST(x1,y1,x2,y2) SQ(x1-x2)+SQ(y1-y2)
#define PB push_back
#define MP make_pair
#define F first
#define S second

using namespace std;

long long int sign, ch;
long long int A[1<<17];
long long int B[1<<17];
long long int C[1<<17];
long long int D[1<<17];

inline void S( long long int &x )
{
        x=0;
        while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
                ch=getchar_unlocked();
        if (ch=='-')
                sign=-1 , ch=getchar_unlocked();
        else
                sign=1;
        do
                x=(x<<3)+(x<<1)+ch-'0';
        while((ch=getchar_unlocked())>='0' && ch<='9');
        x*=sign;
}

bool solve(int N, int M, bool turn , bool opMerge , long long int *A , long long int *B)
{

  if ( N > 0 && M <= 0 ){
    return true;
  }
  if ( M > 0 && N <=  0 ){
    return false;
  }
  if ( N == 1 && M == 1){
    return (A[0] > B[0]);
  }

  if(turn){
    if (A[N-1] > B[M-1]){
      if (opMerge)
        return true;
      return solve(N,--M,false,false, A, B);
    }
    else{
      if (N == 1)
        return false;
      
      long long int sum = N>=2 ? A[N-1] + A[N-2] : A[N-1];
       A[N-2] = sum;
       N--;
       return solve(N, M, false, true, A, B);
    }
  }
  else{
    if (B[M-1] > A[N-1]){
      if (opMerge)
        return false;
      return solve(--N, M, true, false, A, B);
    }
    else{
      if (M == 1)
        return true;
      
      long long int sum = M>=2 ? B[M-1] + B[M-2] : B[M-1];
  
      B[M-2] = sum;
      M--;
      return solve(N, M, true, true, A, B);
    } 
  }
      
}
bool merge(int N , int M , long long int *A,  long long int *B)
{
  long long int sum = A[N-1] + A[N-2];
  
  A[N-2] = sum;
  N--;
  
  return solve(N, M, false, true, A, B);
}
bool takeOver(int N, int M , long long int *A , long long int *B)
{
  if (A[N-1] > B[M-1])
    return solve(N,--M, false,  false , A, B);
  return false;
}
int main()
{
  int N, M, i, j, test = 0;
  while(scanf("%d%d",&N,&M) != EOF){
    test++;
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(C,0,sizeof(C));
    memset(D,0,sizeof(D));

    FOR(i,0,N-1){
      S(A[i]);
      C[i] = A[i];
    }
    FOR(i,0,M-1){
      S(B[i]);
      D[i] = B[i];
    }
  
    sort(A, A+N);
    sort(B, B+M);
    sort(C, C+N);
    sort(D , D+M);
    bool flag = solve(N, M, true, false, A, B);
    if (flag)
      printf("Case %d: Takeover Incorporated\n",test);
    else
      printf("Case %d: Buyout Limited\n",test); 
    /*
    bool flag1 = merge(N,M, A, B);

    if (flag1)
      printf("Case %d: Takeover Incorporated\n",test);
    else{
      bool flag2 = takeOver(N,M , C, D);
      if (flag2)
        printf("Case %d: Takeover Incorporated\n",test);
      else
        printf("Case %d: Buyout Limited\n",test); 
    }
    */
  }
  
  return 0;
}

