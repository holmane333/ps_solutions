#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		int n, ary[100001];
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(int), cmpfunc);
		int max = INT_MIN;
		for (int i = 0; i < n - 2; i++) {
			max = max > ary[i + 2] - ary[i] ? max : ary[i + 2] - ary[i];
		}
		max = max > ary[1] - ary[0] ? max : ary[1] - ary[0];
		max = max > ary[n - 1] - ary[n - 2] ? max : ary[n - 1] - ary[n - 2];
		
		printf("%d\n", max);
	}
	return 0;
}
