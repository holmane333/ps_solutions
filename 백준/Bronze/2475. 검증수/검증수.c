#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, res = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &n);
		res += n * n;
	}
	printf("%d\n", res % 10);

	return 0;
}