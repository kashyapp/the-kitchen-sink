#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char *p;
	char *s[]={
		"100.023",
		"kashyap",
		"   100.023",
		"100.023kashyap",
		"100.023  ",
		"",
		"   ",
		"kash100.023"
	};
	int i;
	for(i=0;i<sizeof(s)/sizeof(char*);++i){
		double f = strtod(s[i],&p);
		printf("%10.4lf,%s,%d\n",f,p,strcmp(p,""));
	}
	return 0;
}
