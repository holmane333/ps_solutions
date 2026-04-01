#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

int cmpfunc(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main() {
   int n;
   int ary[200002], res = 0;
   scanf("%d", &n);
   ary[n] = 0;
   for (int i = 0; i < n; i++) {
      scanf("%d", &ary[i]);
   }
   qsort(ary, n, sizeof(int), cmpfunc);
   /*for (int i = 0; i < n; i++) {
      printf("%d ", ary[i]);
   }*/
   for (int i = n / 2; i < n; i++) {
      if (i == n / 2 && n % 2 == 1) res += ary[i];
      else res += ary[i] * 2;
   }
   printf("%d\n", res);
   return 0;
}