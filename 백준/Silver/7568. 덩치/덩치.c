#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int data[50][3];

int func(int n,int m) {
	if (n < m) return 0;
	int count = 1;
	for (int i = 1; i < m; i++) {
		if ((data[m][0] > data[i][0]) && (data[m][1] > data[i][1])) data[i][2]++;
		else if ((data[m][0] < data[i][0]) && (data[m][1] < data[i][1])) count++;
	}
	data[m][2] = count;
	return func(n, m + 1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &data[i][0], &data[i][1]);
		data[i][2] = 1;
	}
	func(n, 1);
	for (int i = 1; i <= n; i++) {
		printf("%d ", data[i][2]);
	}
}