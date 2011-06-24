#include <stdio.h>

#define N 5
void find_prod(int A[]);
int prod(int temp[],int lower,int upper);

int main()
{
    int A[N]={5,2,3,1,4},i;
    find_prod(A);
    for(i=0;i<N;i++)
        printf("\n%5d",A[i]);
}

void find_prod(int A[])
{
    int i,temp[N];
    for(i=0;i<N;i++)
        temp[i]= A[i];
    for(i=0;i<N;i++)
    {
        A[i] = prod(temp,i+1,N-1) * prod(temp,0,i-1);
    }        
}

int prod(int temp[],int lower,int upper)
{
    int product = 1;
    if(lower<=upper)
    {
        product = temp[lower] * prod(temp,lower+1,upper);
    }
    return product;
}
