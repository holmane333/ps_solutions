#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int cnt = 0;
int n, map[20][20];

int dx[] = { 1, 1, 0 }, dy[] = { 0, 1, 1 };

void dfs(int y, int x, int d) {
	if (y < 0 || y >= n || x < 0 || x >= n || map[y][x]) return;
	if (d == 1) if (map[y - 1][x] || map[y][x - 1]) return;
	
	if (y == n - 1 && x == n - 1) {
		cnt++;
		return;
	}
	
	switch (d)
	{
	case 0:
		for (int i = 0; i < 2; i++)
			dfs(y + dy[i], x + dx[i], i);
		break;
	case 1:
		for (int i = 0; i < 3; i++)
			dfs(y + dy[i], x + dx[i], i);
		break;
	case 2:
		for (int i = 1; i < 3; i++)
			dfs(y + dy[i], x + dx[i], i);
	}
	
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 1, 0);

	printf("%d\n", cnt);

	return 0;
}