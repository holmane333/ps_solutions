#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main()
{
	int total1 = 0, total2 = 0, n;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &n);
		total1 += n;
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &n);
		total2 += n;
	}
	printf("%d\n", total1 >= total2 ? total1 : total2);
	return 0;
}