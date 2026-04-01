#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)


int main() {
   int n;
   scanf("%d", &n);
   int ary[102], res[102] = { 0, }, max = 0, c = 0, idx = 0;
   for (int i = 0; i < n; i++) {
      scanf("%d", &ary[i]);
      res[ary[i]]++;
   }
   for (int i = 1; i <= n; i++) {
      if (res[i] == max) {
         c++;
       }
      else if (res[i] > max) {
         max = res[i];
         c = 0;
         idx = i;
      }
   }
   if (c != 0 || max == 0) {
      printf("skipped\n");
   }
   else {
      printf("%d\n", idx);
   }
   
   return 0;
}