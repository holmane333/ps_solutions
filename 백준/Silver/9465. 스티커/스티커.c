#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int dp[100001];

int main() {
	int i, j, n, t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		scanf("%d", &n);
		int d[2][100001], a[2][100001];
		for (i = 0; i <= 1; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		d[0][0] = d[1][0] = 0;
		d[0][1] = a[0][1];
		d[1][1] = a[1][1];
		for (i = 2; i <= n; i++) {
			d[0][i] = max(d[1][i - 1], d[1][i - 2]) + a[0][i];
			d[1][i] = max(d[0][i - 1], d[0][i - 2]) + a[1][i];
		}
		printf("%d\n", max(d[0][n], d[1][n]));
	}
}