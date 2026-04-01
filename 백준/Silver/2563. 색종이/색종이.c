#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int data[101][101] = { 0, };

void mtrx(int n, int m) {
	for (int i = m; i < m + 10; i++) {
		for (int j = n; j < n + 10; j++) {
			data[i][j] = 1;
		}
	}
}

int sum1() {
	int sum = 0;
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (data[i][j]) sum++;
		}
	}
	return sum;
}

int main() {
	int n, sum = 0, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		mtrx(x, y);
	}
	printf("%d\n", sum1());
	return 0;
}