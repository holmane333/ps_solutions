#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)


int main() {
   int n, idx = 0;
   double ary[100001], res = 0.0, max = -1;
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf("%lf", &ary[i]);
      if (max < ary[i]) {
         max = ary[i];
         idx = i;
      }
   }
   for (int i = 0; i < n; i++) {
      if (i == idx) res += ary[i];
      else res += ary[i] / 2;
   }
   printf("%lf\n", res);

   return 0;
}