#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
   int n, m;
   int ary[1001][1001], path[5001][2], idx = 0;
   scanf("%d %d", &n, &m);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         scanf("%d", &ary[i][j]);
      }
   }
   for (int i = 0; i < m; i++) {
      if (i == m - 1 && (n + m) % 2 == 0) continue;
      path[idx][0] = 0;
      path[idx++][1] = i;
   }
   for (int i = 1; i < n; i++) {
      path[idx][0] = i;
      path[idx++][1] = m - 1;
   }
   printf("%d\n", idx * 2);
   for (int i = 0; i < idx; i += 2) {
      printf("%d %d\n", path[i][0], path[i][1]);
      printf("%d %d\n", path[i + 1][0], path[i + 1][1]);
      printf("%d %d\n", path[i][0], path[i][1]);
      printf("%d %d\n", path[i + 1][0], path[i + 1][1]);
   }
   return 0;
}