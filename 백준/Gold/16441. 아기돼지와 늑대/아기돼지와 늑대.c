#include <stdio.h>
#pragma warning(disable:4996)

int n, m;
char map[101][101];
int check[101][101];
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};

void dfs(int x, int y) {
	check[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cy >= 0 && cx < n && cy < m && !check[cx][cy] && map[cx][cy] != '#') {
			if (map[cx][cy] == 'P') {
				map[cx][cy] = '.';
				dfs(cx, cy);
			}
			else if (map[cx][cy] == 'W') {
				dfs(cx, cy);
			}
			else {
				while (cx >= 0 && cy >= 0 && cx < n && cy < m && map[cx][cy] == '+') {
					cx += dx[i];
					cy += dy[i];
				}
				if (cx >= 0 && cy >= 0 && cx < n && cy < m && map[cx][cy] == '#') {
					cx -= dx[i];
					cy -= dy[i];
				}
				if (!check[cx][cy]) {
					if (map[cx][cy] == 'P') map[cx][cy] = '.';
					dfs(cx, cy);
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	int q[10001][3], idx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.') map[i][j] = 'P';
			if (map[i][j] == 'W') {
				q[idx][0] = i;
				q[idx++][1] = j;
			}
		}
	}

	for (int i = 0; i < idx; i++) {
		if (!check[q[i][0]][q[i][1]])
			dfs(q[i][0], q[i][1]);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%s\n", map[i]);
	}
	return 0;
}
