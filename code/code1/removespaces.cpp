#include <stdio.h>
#include <string.h>
#include <ctype.h>

//inplace remove spaces from the input string
void removespaces(char* str){
	int to=0;
	for(int from=0; str[from]!='\0'; from++)
		if(!isspace(str[from]))
			str[to++]=str[from];
	str[to]='\0';
}

int main(){
	char *str=NULL;
	size_t size=0;
	size_t n;
	while(-1 != getline(&str,&size,stdin)){
		removespaces(str);
		printf("%s\n",str);
	}
}
