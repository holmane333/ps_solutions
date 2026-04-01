#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))
 
int n, m, map[101][101];
int q[20001][3], ft, rr;
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};
 
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int sx = x + dx[i];
		int sy = y + dy[i];
		if (sx < 0 || sx >= n || sy < 0 || sy >= m) continue;
		if (map[sx][sy] == 0) {
			map[sx][sy] = 2;
			dfs(sx, sy);
		}
	}
}
 
int bfs() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) cnt++;
					else if (map[i + dx[k]][j + dy[k]] == 2) cnt++;
				}
				if (cnt >= 2) {
					q[ft][0] = i;
					q[ft++][1] = j;
				}
			}
		}
	}
	while (ft != rr) {
		for (int i = 0; i < ft; i++) {
			int x, y;
			x = q[i][0];
			y = q[i][1];
			map[x][y] = 2;
			dfs(x, y);
		}
		ft = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) cnt++;
						else if (map[i + dx[k]][j + dy[k]] == 2) cnt++;
					}
					if (cnt >= 2) {
						q[ft][0] = i;
						q[ft++][1] = j;
					}
				}
			}
		}
		count++;
	}
 
 
	return count;
}
 
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	map[0][0] = 2;
	dfs(0, 0);
	
	printf("%d\n", bfs());
	return 0;
}