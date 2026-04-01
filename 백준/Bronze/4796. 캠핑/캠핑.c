#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, m, l;
	for (int i = 1;; i++) {
		scanf("%d %d %d", &n, &m, &l);
		if (n == 0 && m == 0 && l == 0) break;
		printf("Case %d: %d\n", i, (l / m) * n + (l % m > n ? n : l % m));
	}


	return 0;
}