#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main()
{
	int n, cnt = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &n);
		cnt += n;
	}
	printf("%d\n%d\n", cnt / 60, cnt % 60);

	return 0;
}