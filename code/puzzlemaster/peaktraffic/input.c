#include <stdio.h>
#include <time.h>

static unsigned long x = 123456789;
static unsigned long y = 362436069;
static unsigned long z = 521288629;
static unsigned long w = 88675123;
static unsigned long v = 886756453;

static unsigned long xorshift(void) {
unsigned long t;
t = x ^ (x >> 7);
x = y;
y = z;
z = w;
w = v;
v = v ^ (v << 6) ^ t ^ (t << 13);
return (y + y + 1) * v;
}

int main(void) {
time_t t;
char buf[26];
unsigned long i, a, b, j, r;
time(&t);
for(i = 0; i < (1UL << 20); ++i) {
a = 0;
b = 0;
for(j = 0; j < 12; ++j) {
a <<= 1;
b <<= 1;
r = xorshift() % 20;
if(r < 11) a |= 1;
if(r < 8 || r >= 18) b |= 1;
}
ctime_r(&t, buf);
buf[24] = '\0';
printf("%s\t%ld@example.com\t%ld@example.com\n", buf, a, b);
++t;
}
return 0;
}
