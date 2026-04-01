#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, k, res = 0;
int dx[] = { 1,-1,1 }, dy[] = { 0,0,1 };
int map[3][100002], check[3][100002];

void dfs(int y, int x, int cnt) {
	check[y][x] = cnt;
	if (n <= x) {
		res = 1;
		return;
	}

	for (int i = 0; i < 3 && !res; i++) {
		int cy = (y + dy[i]) % 2;
		int cx = x + dx[i];
		if ((cnt <= cx && (!check[cy][cx] || check[cy][cx] > cnt + 1) && map[cy][cx]) || n - 1 < cx) dfs(cy, cx, cnt + 1);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	dx[2] = k;
	char c;
	for (int j = 0; j < 2; j++) {
		getchar();
		for (int i = 0; i < n; i++) {
			scanf("%c", &c);
			map[j][i] = (int)(c - '0');
		}
	}
	if (map[0][0]) dfs(0, 0, 1);
	printf("%d\n", res);
	return 0;
}
