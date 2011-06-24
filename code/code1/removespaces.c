#include <stdio.h>
#include <string.h>


void func(char a[]){
    int len = strlen(a);
    int i = 0;
    int j = 0;
    for(i = 0; i< len; i++) {
        if (a[i] != ' ') {
            i++; j++;
        }
        else {
            j = i;
        }
        if (a[i] == ' ') {
            i++;
        }
        else {
            a[i] = a[j];
            j++;
        }
    } 
}
void removespaces(char a[]){
    char *i = a;
    char *j = a;
    while (*i != '\0') {
        if (*i != ' ') {
            *j++ = *i;
        }
        i++;
    }
    *j = '\0';
}

int main(){
    char a[] = "i am fine, thanks you   please you are a good  boy";
    char *b = strdup(a);
    printf("%s\n",a);
    func(a);
    printf("%s\n",a);
    removespaces(b);
    printf("%s\n",b);
}
