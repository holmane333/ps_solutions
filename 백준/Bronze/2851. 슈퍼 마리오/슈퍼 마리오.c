#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main()
{
	int cnt = 0, n;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		if (cnt + n > 100) {
			cnt = cnt + n - 100 > abs(cnt - 100) ? cnt : cnt + n;
			break;
		}
		else cnt += n;
	}
	printf("%d\n", cnt);
	return 0;
}