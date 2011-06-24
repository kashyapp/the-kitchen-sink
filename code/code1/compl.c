#include <stdio.h>
#include <assert.h>
int main(int argc, char **argv){
	assert(argc>1 || !"integer argument needed");
	long long a = atol(argv[1]);
	unsigned long long b = ~a;
	long long c = ~a;
	printf("%16llx %lld %llu\n",a,a,a);
	printf("%16llx %lld %llu\n",b,b,b);
	printf("%16llx %lld %llu\n",c,c,c);
	printf("%16llx %lld %llu\n",~a,~a,~a);
	return 0;
}
