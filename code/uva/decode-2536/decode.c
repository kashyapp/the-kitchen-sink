#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int i;
  for(i=1; i<=n; ++i) {
    printf("Case %d: ", i);

    char str[201];
    char *s = &str[0];
    scanf("%s", str);

    char c;
    while ((c = *s) != '\0') {
      s++;
      int m = strtol(s, &s, 10);
      int j;
      for(j=0; j<m; ++j) {
        putchar(c);
      }
    }
    putchar('\n');
  }
  return 0;
}
