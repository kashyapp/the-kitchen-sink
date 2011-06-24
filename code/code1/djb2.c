#include <stdio.h>
#include <assert.h>

inline unsigned long djb2(char *str){
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

int main(int argc, char **argv){
	assert(argc>1);
	printf("%s\t%lu\n",argv[1],djb2(argv[1]));
	return 0;
}

