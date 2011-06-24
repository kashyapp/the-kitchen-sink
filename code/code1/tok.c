#include <stdio.h>
#include <string.h>
char* tok(char *str){
	static char *ptr;
	if(str != NULL)
		ptr = str;
	else
		str = ptr;

	if(ptr==NULL)	return NULL;

	for(; *ptr != ';' && *ptr !='\0'; ptr++);
	
	if(*ptr == '\0')
		ptr=NULL;
	else
		*ptr++ = '\0';

	return str;
}

int main(){
	char line[200];
	int count=0;
	int maxcount = 5; //have to see 5 strings
	while(fgets(line,200,stdin)){
		char *ll = line;
		int len = strlen(line);
		if(len && line[len-1] == '\n') line[len-1] = '\0';
		char *word = tok(ll);
		//char *word = strsep(&ll,";");
		while(word!=NULL){
			printf("%s|",word);
			word = tok(NULL);
			//word = strsep(&ll,";");
		}
		printf("...EOL...\n");
	}
	return 0;
}
