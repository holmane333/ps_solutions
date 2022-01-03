#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, m;
int map[501][501], check[501][501], cnt = 0, max = INT_MIN, count = 0;

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

void dfs(int y, int x) {
	check[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (cy >= 0 && cy < n && cx >= 0 && cx < m && !check[cy][cx] && map[cy][cx]) dfs(cy, cx);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt = 0;
			if (!check[i][j] && map[i][j]) {
				count++;
				dfs(i, j);
			}
			max = max > cnt ? max : cnt;
		}
	}

	printf("%d\n%d\n", count, max);
	return 0;
}
