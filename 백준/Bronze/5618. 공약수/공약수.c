#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int gcd(int n, int m) {
	if (n < m) {
		int temp = m;
		m = n;
		n = temp;
	}
	if (m != 0) return gcd(m, n % m);
	return n;
}

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n, arr[3], res, ary[10000], idx = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	res = n == 2 ? gcd(arr[0], arr[1]) : gcd(gcd(arr[0], arr[1]), arr[2]);
	for (int i = 1; i * i <= res; i++) {
		if (!(res % i)) {
			if (i * i == res) ary[idx++] = i;
			else {
				ary[idx++] = i;
				ary[idx++] = res / i;
			}
		}
	}
	qsort(ary, idx, sizeof(int), cmpfunc);
	for (int i = 0; i < idx; i++) {
		printf("%d\n", ary[i]);
	}

	return 0;
}