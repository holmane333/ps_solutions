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
	int n, m, data[10001], res = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	qsort(data, n, sizeof(int), cmpfunc);

	if ((abs(data[0])) >= abs(data[n - 1]) && data[0] < 0) {
		res += abs(data[0]);
		for (int i = m; i < n && data[i] < 0; i += m) {
			res += abs(data[i]) * 2;
		}
		for (int i = n - 1; i >= 0 && data[i] > 0; i -= m) {
			res += data[i] * 2;
		}
	}
	else {
		res += abs(data[n - 1]);
		for (int i = 0; i < n && data[i] < 0; i += m) {
			res += abs(data[i]) * 2;
		}
		for (int i = n - m - 1; i >= 0 && data[i] > 0; i -= m) {
			res += data[i] * 2;
		}
	}

	printf("%d\n", res);
	return 0;
}
