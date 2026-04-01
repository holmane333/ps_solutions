#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int data[300];
int res[500];
int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	qsort(data, n, sizeof(int), compare);
	m = data[1] - data[0];
	for (int i = 2; i < n; i++) {
		m = gcd(m, data[i] - data[i - 1]);
	}
	int len = 0;
	for (int i = 2; i * i <= m; i++) {
		if (!(m % i)) {
			res[len++] = i;
			if (i!=m/i) res[len++] = m / i;
		}
	}
	res[len++] = m;
	qsort(res, len, sizeof(int), compare);
	for (int i = 0; i < len; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}