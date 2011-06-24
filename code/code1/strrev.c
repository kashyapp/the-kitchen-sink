#include <stdio.h>
#include <assert.h>

int main(int argc, char **argv){
    assert(argc>1);
    reverse1(argv[1], 0);
    printf("%s\n",argv[1]);
    return 0;
}

int reverse1(char *s, int i){
    if(s[i] == '\0')
        return 0;
    int j = reverse1(s,i+1);
    if(j<i){ 
        char t = s[j];
        s[j]=s[i];
        s[i]=t;
    }
    return j+1;
}

int reverse(char *s, int i){
    if(s[i] == '\0')
        return 0;
    char t = s[i];
    int j = reverse(s,i+1);
    s[j]=t;
    return j+1;
}

