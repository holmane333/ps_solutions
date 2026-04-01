#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct element* node;
typedef struct element {
   int data;
   node link;
}element;

int main() {
   int n, m;
   int* recipe[200002];
   scanf("%d %d", &n, &m);
   for (int i = 0; i <= n; i++) recipe[i] = NULL;
   node* next_node = malloc(sizeof(element) * (n + 2));
   for (int i = 0; i <= n; i++) {
      next_node[i] = malloc(sizeof(element));
      next_node[i]->link = NULL;
   }
   int t, ary[400002] = { 0, }, medicine, res[200002] = { 0, }, data;
   for (int i = 0; i < m; i++) {
      scanf("%d", &t);
      recipe[i] = (int*)malloc(sizeof(int) * (t + 2));
      for (int j = 1; j <= t; j++) {
         scanf("%d", &recipe[i][j]);
         node new_node = malloc(sizeof(element));
         new_node->data = i;
         new_node->link = next_node[recipe[i][j]]->link;
         next_node[recipe[i][j]]->link = new_node;
      }
      scanf("%d", &medicine);
      recipe[i][0] = t;
      recipe[i][t + 1] = medicine;
   }
   scanf("%d", &t);
   int queue[200002], ft = 0, rr = 0;
   for (int i = 0; i < t; i++) {
      scanf("%d", &data);
      res[data] = 1;
      queue[rr++] = data;
   }
   int c;
   int curr;
   node check;
   while (ft != rr) {
      curr = queue[ft++];
      if (ft > 200000) ft = 0;
      check = next_node[curr]->link;
      while (check != NULL) {
         c = 0;
         if (!res[recipe[check->data][recipe[check->data][0] + 1]]) {
            for (int j = 1; j <= recipe[check->data][0]; j++) {
               if (!res[recipe[check->data][j]]) {
                  c = 1;
                  break;
               }
            }
            if (c == 0) {
               res[recipe[check->data][recipe[check->data][0] + 1]] = 1;
               queue[rr++] = recipe[check->data][recipe[check->data][0] + 1];
               if (rr > 200000) rr = 0;
            }
         }
         check = check->link;
      }
   }
   int cnt = 0;
   for (int i = 0; i <= n; i++) if (res[i]) cnt++;
   printf("%d\n", cnt);
   for (int i = 0; i <= n; i++) {
      if (res[i]) printf("%d ", i);
   }
   puts("");

   return 0;
}