#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE  1

#define FROMPAT "From "
#define SUBPAT "Subject: "
#define SYNCPAT "/sbin/sync.sh"

int main() {
    int print = FALSE;

    char *buffer = NULL;
    int bufsize = 0;
    int buflen = 0;
    
    char *line = NULL;
    int size = 0;
    int len = 0;
    
    while((len = getline(&line, &size, stdin)) != -1) {
       if (strstr(line, SUBPAT) != NULL && strstr(line,SYNCPAT) == NULL ) {
            print = TRUE;
        } 
        else if(strstr(line, FROMPAT) != NULL) {
            if (print) {
                fwrite(buffer, 1, buflen, stdout);
            }
            print = FALSE;
            buflen = 0;
        }

        //add line to buffer
        int temp = buflen;
        buflen += len;
        if (buflen > bufsize) {
            bufsize = buflen * 2;
            buffer = realloc(buffer, bufsize);
            fprintf(stderr, "Buffer resized to %d\n", bufsize);
        }
        memcpy(buffer + temp, line, len);
     }
    return 0;
}
