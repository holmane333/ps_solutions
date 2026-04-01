#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
	int tc, m, n;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		scanf("%d %d", &n, &m);
		printf("1\n");
		for (int i = 0; i < m; i++) printf("(%d,%d)\n", 0, i);
		for (int i = 1; i < n; i++) {
			if (i % 2) for (int j = m - 1; j > 0; j--) printf("(%d,%d)\n", i, j);
			else for (int j = 1; j < m; j++) printf("(%d,%d)\n", i, j);
		}
		for (int i = n - 1; i > 0; i--) printf("(%d,%d)\n", i, 0);
		
	}
	return 0;
}
