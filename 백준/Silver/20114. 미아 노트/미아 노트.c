#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)


int main() {
   int n, row, col;
   char ary[11][1001], res[101] = { 0, };
   scanf("%d %d %d", &n, &row, &col);
   res[n] = '\0';
   for (int i = 0; i < row; i++) {
      scanf("%s", ary[i]);
   }
   for (int i = 0; i < n; i++) {
      res[i] = '?';
      for (int j = 0; j < row; j++) {
         if (res[i] != '?') break;
         for (int k = 0; k < col; k++) {
            if (ary[j][i * col + k] != '?') {
               res[i] = ary[j][i * col + k];
               break;
            }
         }
      }
   }
   printf("%s\n", res);

   return 0;
}