#include <stdio.h>
#include <assert.h>

double atof(char *a){
	double f = 0;
	for(;*a != '\0' && *a != '.' ;a++)
			f = f*10 + (*a - '0');
	if (*a == '.') a++;
	for(int div=10;*a != '\0' && *a != '.' ;a++, div *= 10)
		f += (double)(*a - '0') / (double)div;
	
	return f;
}

int main(int argc, char **argv){
	assert(argc > 1);
	printf("%s %50.20f\n",argv[1],atof(argv[1]));
	printf("%05d%05d\n",1234567,12);
	return 0;
}
