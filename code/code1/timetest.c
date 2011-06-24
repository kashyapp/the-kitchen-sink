#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if(argc>1){
        setenv("TZ",argv[1],1);
    }
    struct timeval now_tv;
    time_t now;
    time(&now);
    gettimeofday(&now_tv, NULL);

    printf("%d\n", now);
    printf("%d %d \n",now_tv.tv_sec,now_tv.tv_usec);

    struct tm t;
    gmtime_r(&now, &t);
    printf("gmtime:\n%4d %4d %4d %4d %4d %4d %4d %4d\n",
            t.tm_year+1900,
            t.tm_mon+1,
            t.tm_mday,
            t.tm_hour,
            t.tm_min,
            t.tm_sec,
            t.tm_wday,
            t.tm_yday
            );
    localtime_r(&now, &t);
    printf("localtime:\n%4d %4d %4d %4d %4d %4d %4d %4d\n",
            t.tm_year+1900,
            t.tm_mon+1,
            t.tm_mday,
            t.tm_hour,
            t.tm_min,
            t.tm_sec,
            t.tm_wday,
            t.tm_yday
            ); 

    return 0;

}
