#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n = 12, m = 6;
char map[20][10], submap[20][10];
int res[101], check[20][10], idx = 0, c = 0, count = 1;

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

void dfs(int y, int x, char t, int mark) {
	check[y][x] = mark;
	if (count >= 4 && c==0) {
		c = 1;
		res[idx++] = mark;
	}
	for (int i = 0; i < 4; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (cy >= 0 && cy < n && cx >= 0 && cx < m && !check[cy][cx] && map[cy][cx] == t) {
			count++;
			dfs(cy, cx, t, mark);
		}
	}
}

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
		}
		getchar();
	}
	int cnt = 0, mark;
	while (1) {
		memset(check, 0, sizeof(check));
		mark = 1;
		idx = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				submap[i][j] = '.';
				c = 0;
				count = 1;
				if (!check[i][j] && map[i][j] != '.') dfs(i, j, map[i][j], mark++);
			}
		}
		if (idx == 0) break;
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (check[j][k] == res[i]) check[j][k] = 0;
				}
			}
		}
		
		for (int i = 0; i < m; i++) {
			int k = n-1;
			for (int j = n-1; j >= 0; j--) {
				if (check[j][i]) submap[k--][i] = map[j][i];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = submap[i][j];
			}
		}
		cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}