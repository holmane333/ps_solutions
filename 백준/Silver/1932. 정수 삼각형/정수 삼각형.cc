//noj.am/1932
//Dynamic Programming
#include <stdio.h>
#pragma warning(disable:4996)
int max(int x, int y) { return x > y ? x : y; }

int main() {
	int n, i, j;
	int sum = 0;
	int tri[500][500] = { 0, };
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}
	sum = tri[0][0];
	for (i = 1; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0) {
				tri[i][j] += tri[i - 1][0];
			}
			else if (i == j) {
				tri[i][j] += tri[i - 1][j - 1];
			}
			else {
				tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
			}
			sum = max(sum, tri[i][j]);
		}
	}

	printf("%d", sum);

	return 0;
}