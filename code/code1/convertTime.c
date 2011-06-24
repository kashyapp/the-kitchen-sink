#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv){
	assert(argc>1 || !"we need input time_t");
	time_t t;
	int ret;
	ret=sscanf(argv[1],"%d",&t);
	assert(ret||"count not convert to time_t");
	char *s=ctime(&t);
	printf("localtime: %s",s);
	return 0;
}
