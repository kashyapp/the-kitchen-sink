#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
void
logHeapSize()
{
  int32_t vmData = 0;

  const char *procStatusPath = "/proc/self/status";
  FILE *f = fopen(procStatusPath, "r");
  if (f != NULL)
    {
      while (f)
        {
          char line[256]; 
          if (! fgets(line, 256 - 1, f))
             break;

          if( sscanf(line, "VmData: %d kB", &vmData) == 1 )
             break;
         }
      fclose(f);
    }

  if( !vmData )
    {
		printf("Error parsing VmData from %s\n", procStatusPath);
    }
  printf("VmData: %d\n", vmData);
}

int main(int argc, char **argv){
	size_t i;
	assert(argc>1);
	assert(sscanf(argv[1],"%d",&i));
	logHeapSize();
	getchar();
	int *foo = (int*) calloc(i,1024);
	if(foo==NULL){
		perror("foo");
		printf("errno: %d\n",errno);
	}
	logHeapSize();
	getchar();
	free(foo);
	logHeapSize();
	return 0;
}



