#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int map[20][20], temp[20][20], temp2[20][20], res[20][20], n, m;
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};

void change(int x, int y) {
	temp[x][y] ^= 1;
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
		temp[cx][cy] ^= 1;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	
	long long len = 1 << m;
	int cnt = 0, minv = 2e9;
	for (long long b = 0; b < len; ++b) {
		cnt = 0;
		memcpy(temp, map, sizeof(temp));
		memset(temp2, 0, sizeof(temp2));
		for (int i = 0; i < m; ++i) {
			if (b & (long long)(1 << i)) {
				++cnt;
				change(1, m - i);
				temp2[1][m - i] = 1;
			}
		}
		
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (temp[i - 1][j]) {
					++cnt;
					change(i, j);
					temp2[i][j] = 1;
				}
			}
		}
		
		int c = 0;
		for (int i = 1; i <= n; ++i) {
			if (c) break;
			for (int j = 1; j <= m; ++j) {
				if (temp[i][j]) {
					c = 1;
					break;
				}
			}
		}
		
		if (!c && cnt < minv) {
			minv = cnt;
			memcpy(res, temp2, sizeof(res));
		}
	}
	
	if (minv == 2e9) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
