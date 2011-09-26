#include <stdio.h>
int main(int argc, char *argv[])
{
    char *p="String";
    int x=0;
    printf("%x %x\n", p, "String");
    if(p=="String")
    {
        printf("Pass 1");
        if(p[sizeof(p)-2]=="g")
            printf("Pass 1");
        else
            printf("Fail 1");
    }
    else
    {    
        printf("Fail 2");
        if(p[sizeof(p)-2]=="g")
            printf("Pass 2");
        else   	 
            printf("Fail 2");
    }
}
