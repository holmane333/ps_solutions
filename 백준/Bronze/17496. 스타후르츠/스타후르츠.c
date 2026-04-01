#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
  int n, t, c, p, res;
  scanf("%d %d %d %d", &n, &t, &c, &p);
  res=(n-1)/t*c*p;
  printf("%d\n", res);
  return 0;
}
