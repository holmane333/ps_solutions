#include <stdio.h>
#pragma warning(disable:4996)

int n, ary[100][100], sum1[100][100], sum2[100][100];

int loop(int x1, int y1, int x2, int y2, int d) {
	if (x1 > x2 || y1 > y2) return 0;
	if (x1 <= 0 || x1 > n || x2 <= 0 || x2 > n || y1 <= 0 || y1 > n || y2 <= 0 || y2 > n) return 0;
	int jewel = 0, temp = 0;
	temp = sum1[x2][y2] - sum1[x1 - 1][y2] - sum1[x2][y1 - 1] + sum1[x1 - 1][y1 - 1];
	jewel = sum2[x2][y2] - sum2[x1 - 1][y2] - sum2[x2][y1 - 1] + sum2[x1 - 1][y1 - 1];
	//printf("%d %d %d %d %d %d: %d %d %d %d, %d %d %d %d\n", x1, y1, x2, y2, temp, jewel, sum1[x2][y2], sum1[x1 - 1][y2], sum1[x2][y1 - 1], sum1[x1 - 1][y1 - 1], sum2[x2][y2], sum2[x1 - 1][y2], sum2[x2][y1 - 1], sum2[x1 - 1][y1 - 1]);
	if (jewel == 1 && temp == 0) return 1;
	if (jewel - 1 > temp || jewel == 0) return 0;
	
	int res = 0;
	if (d) {
		for (int i = x1 + 1; i < x2; ++i) {
			if (sum2[i][y2] - sum2[i - 1][y2] - sum2[i][y1 - 1] + sum2[i - 1][y1 - 1] != 0 || sum1[i][y2] - sum1[i - 1][y2] - sum1[i][y1 - 1] + sum1[i - 1][y1 - 1] == 0) continue;
			res += loop(x1, y1, i - 1, y2, !d) * loop(i + 1, y1, x2, y2, !d);
			//printf("%d %d\n", loop(x1, y1, i - 1, y2), loop(i + 1, y1, x2, y2));
		}
	}
	else {
		for (int i = y1 + 1; i < y2; ++i) {
			if (sum2[x2][i] - sum2[x2][i - 1] - sum2[x1 - 1][i] + sum2[x1 - 1][i - 1] != 0 || sum1[x2][i] - sum1[x2][i - 1] - sum1[x1 - 1][i] + sum1[x1 - 1][i - 1] == 0) continue;
			res += loop(x1, y1, x2, i - 1, !d) * loop(x1, i + 1, x2, y2, !d);
			//printf("%d %d\n", loop(x1, y1, x2, i - 1), loop(x1, i + 1, x2, y2));
		}
	}
	//printf("%d %d %d %d %d\n", x1, y1, x2, y2, res);
	return res;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) 
			scanf("%d", &ary[i][j]);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			sum1[i][j] = sum1[i][j - 1] + sum1[i - 1][j] - sum1[i - 1][j - 1];
			sum2[i][j] = sum2[i][j - 1] + sum2[i - 1][j] - sum2[i - 1][j - 1];
			if (ary[i][j] == 1) 
				++sum1[i][j];
			else if (ary[i][j] == 2)
				++sum2[i][j];
		}
	}
	/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", sum1[i][j]);
		} puts("");
	} puts("");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", sum2[i][j]);
		} puts("");
	} puts("");*/
	
	int res = loop(1, 1, n, n, 0) + loop(1, 1, n, n, 1);
	if (res == 0) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}
