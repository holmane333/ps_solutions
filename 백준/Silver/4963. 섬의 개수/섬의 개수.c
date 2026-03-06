#include <stdio.h>
#include <memory.h>

int n, m;
int map[100][100], visit[100][100];
int dx[9] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[9] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 8; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];;
		if (!visit[cx][cy] && map[cx][cy]) {
			dfs(cx, cy);
		}
	}
}

int main(void) {
	while (1) {
		int cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &m, &n);
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) scanf("%d", &map[i][j]);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (!visit[i][j] && map[i][j]) {
					++cnt;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
