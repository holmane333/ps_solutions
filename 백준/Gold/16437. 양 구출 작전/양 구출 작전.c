#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 123456

typedef struct island {
   long long cnt;
   int NEXT;
}island;

island I[MAX];

long long escape(int i, long long on)
{
   if (i == 1) return on;
   if (I[i].NEXT != 1 && I[I[i].NEXT].cnt == 0) I[i].NEXT = I[I[i].NEXT].NEXT;

   if (on + I[i].cnt < 0) {
      I[i].cnt += on;
      return 0;
   }
   on += I[i].cnt;
   I[i].cnt = 0;
   i = I[i].NEXT;

   escape(i, on);
}

int main()
{
   int n;
   long long cnt, result = 0;
   char type;
   scanf("%d", &n);

   for (int i = 2; i <= n; i++) {
      getchar();
      scanf("%c %lld %d", &type, &cnt, &I[i].NEXT);
      I[i].cnt = (type == 'S') ? cnt : -cnt;
   }

   for (int i = 2; i <= n; i++)
      result += escape(i, 0);

   printf("%lld", result);

   return 0;
}