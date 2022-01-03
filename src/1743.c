#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, m, map[101][101];
int check[101][101], cnt, max = INT_MIN;

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

void dfs(int y, int x) {
	check[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (cy >= 0 && cy < n && cy >= 0 && cy < n && !check[cy][cx] && map[cy][cx]) dfs(cy, cx);
	}
}

int main() {
	int t, y, x;
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &y, &x);
		map[y - 1][x - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt = 0;
			if (!check[i][j] && map[i][j]) dfs(i, j);
			max = max > cnt ? max : cnt;
		}
	}

	printf("%d\n", max);
	return 0;
}
