#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	n *= m;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &m);
		printf("%d ", m - n);
	}

	return 0;
}