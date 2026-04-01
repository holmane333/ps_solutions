#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int ary[1000001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);
		ary[data]++;
	}
	int res = 0, x;
	scanf("%d", &x);
	for (int i = 1; i <= x / 2; i++) {
		if (x - i >= 1000000) continue;
		if (x - i == i) continue;
		res += ary[i] * ary[x - i];
	}
	printf("%d\n", res);
	return 0;
}