#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	long long int n, len[100001], data[100001], total = 0, idx = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%lld", &len[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &data[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		idx = data[idx] > data[i] ? i : idx;
		total += len[i] * data[idx];
	}
	printf("%lld\n", total);
	return 0;
}