#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
      int count,max,t,flag;
        int h[100]={0};
        scanf("%d",&t);
        for(int i=0;i<t;i++){
            scanf("%d",&h[i]);
        }
        max=0;
        for(int j=0;j<t;j++){
            int k=j+1;
            count=0;  
            while(k< t && h[j]>1){
               if(h[j]>=h[k]){
                    h[j]--;
                    h[k]++;
                    count++;
		}
                else{ k++;}
           }
           if(max<count) max=count;
        }
        printf("%d",max);
    return 0;
}
