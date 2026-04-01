#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)


int main() {
   int n, idx = 0, L;
   double ary[200002], sum[200002] = { 0, }, res = 0.0, max = -1;
   scanf("%d %d", &n, &L);
   ary[n] = 0;
   for (int i = 0; i < n; i++) {
      scanf("%lf", &ary[i]);
      sum[i] = ary[i];
   }
   for (int i = n-2; i >=0; i--) {
      sum[i] += sum[i + 1];
   }
   for (int i = 0; i < n - 1; i++) {
      res = sum[i + 1] / (double)(n - i - 1);
      if (res <= ary[i] - L || res >= ary[i] + L) {
         printf("unstable\n");
         return 0;
      }
   }
   printf("stable\n");
   return 0;
}