#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <tr1/cstdint>
using namespace std;
#define INF 2000000000
#define FOR(i,a,n) for(int i=a,_n=n; i<_n; i++)
 
int N, K;
int arr[605], pos[605];
 
//Check whether the number x you guess satisfy the number of maximum camping needed
 
bool check(int x){
     int y = x, camp = 0;
     FOR (i, 0, N+1){
         int dif = pos[i+1] - pos[i];
         if ( y >= dif ) y -= dif;
         else{
              camp++;
              y = x-dif;              
         }    
         if ( camp > K || y < 0 ) return false;
     }     
     return true;
}
 
//Main 
 
int main(){
    while ( scanf("%d %d", &N, &K) == 2 ){
          FOR (i, 1, N+2) scanf("%d", &arr[i]);
 
          pos[0] = 0;
          FOR (i, 1, N+2) pos[i] = arr[i] + pos[i-1];       
 
          int left = pos[0], right = pos[N+1];
          int dist = INF;
 
          while ( left <= right ){
                int mid = (left+right)/2;
                if ( check(mid) ) dist = min(dist, mid), right = mid-1;
                else left = mid+1;
          }
 
          printf("%d\n", dist);
    }
    return 0;
}
