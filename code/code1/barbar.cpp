#include <stdio.h>

long mul(int *a,int l,int r){
    int left;
    if(l){
        left = mul(a,l-1,r*a[l]);
    }
    else{
        left = 1;
    }
    long t=a[l];
    a[l]=left*r;
    return left*t;
}

int main(){
    int a[]={4,5,7,2,1,3};
    for(int i=0;i<6;++i)
        printf("%ld",a[i]);
    long k = mul(a,5,1);
    printf("\n%d\n",k);
    for(int i=0;i<6;++i)
        printf("%ld ",a[i]);
    printf("\n");

    return 0;
}


