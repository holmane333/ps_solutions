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
	int n, ary[5001], data[400001], res = 0;
	scanf("%d", &n);
	memset(data, 0, sizeof(data));
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
		for (int j = 0; j < i; j++) {
			if (data[ary[i] - ary[j] + 200000]) {
				res++;
				break;
			}
		}
		for (int j = 0; j <= i; j++) {
			data[ary[i] + ary[j] + 200000] = 1;
		}
	}
	printf("%d\n", res);
	return 0;
}
