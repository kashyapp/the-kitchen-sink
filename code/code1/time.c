#include <time.h>
#include <stdio.h>

extern char* tzname[2];

int main(){
    struct tm t;
    char buf[256];

    scanf("%d %d %d %d %d %d",&t.tm_sec,
                            &t.tm_min,
                            &t.tm_hour,
                            &t.tm_mday,
                            &t.tm_mon,
                            &t.tm_year);

    printf("%d\n",mktime(&t));
    strftime(buf, 256, "%a %b %d %H:%M:%S %Y %z", &t);
    printf("%s\n", buf);

    time_t tt = mktime(&t);

    struct tm g;
    gmtime_r(&tt, &g);
    strftime(buf, 256, "%a %b %d %H:%M:%S %Y %z", &g);
    printf("%s\n", buf);
    
    return 0;
}
