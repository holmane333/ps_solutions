#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)


int main() {
   int n;
   scanf("%d", &n);
   char ary[101][101];
   for (int i = 0; i < n; i++) {
      scanf("%s", ary[i]);
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (ary[i][j] != ary[j][i]) {
            printf("NO\n");
            return 0;
         }
      }
   }
   printf("YES\n");
   return 0;
}