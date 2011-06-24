#include <stdio.h>
#include <sys/time.h>

class Timer {
    struct timeval t0;
    const char* mesg;
    public:
    Timer(char *_mesg) : mesg(_mesg) {
        gettimeofday(&t0, NULL);
    }
    ~Timer() {
        struct timeval t1;
        gettimeofday(&t1, NULL);
        long delta = 1000000 * (t1.tv_sec - t0.tv_sec) + (t1.tv_usec - t0.tv_usec);
        fprintf(stderr, "%s: %d\n", mesg, delta);
    }
};

int main() {
    int i;
    Timer t("");
#ifdef SCANF
    while (scanf("%d",&i) == 1) {
        printf("%d\n",i);
    }
#else
    char *line = NULL;
    size_t len = 0;
    size_t read = 0;
    while ((read = getline(&line,&len,stdin)) != -1) {
        char *current = line;
        int t;
        for (size_t j=0; j < read; j++) {
            i = *(line + j) - '0';
        }
    }
#endif
    return 0;
}
