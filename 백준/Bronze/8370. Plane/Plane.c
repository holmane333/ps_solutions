#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
  int n1, k1, n2, k2, res;
  scanf("%d %d %d %d", &n1, &k1, &n2, &k2);
  res=n1*k1+n2*k2;
  printf("%d\n", res);
  return 0;
}
