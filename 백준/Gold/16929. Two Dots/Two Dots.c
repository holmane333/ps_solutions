#include <stdio.h>
#pragma warning(disable:4996)

int n, m, res;
char map[51][51];
int visit[51][51];
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};

void dfs(int back_x, int back_y, int x, int y, int cnt, char c, int num) {
	if (res == 1) return;
	for (int i = 0; i < 4; i++) {
		int sx = dx[i] + x;
		int sy = dy[i] + y;	
		if (sx < 0 || sx >= n || sy < 0 || sy >= m) continue;
		if (visit[sx][sy] == num && map[sx][sy] == c && (sx != back_x || sy != back_y)) {
			if (cnt >= 4) res = 1;
			return;
		}
		if (!visit[sx][sy] && map[sx][sy] == c) {
			visit[sx][sy] = num;
			dfs(x, y, sx, sy, cnt + 1, c, num);
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (res == 1) break;
			if (!visit[i][j]) {
				visit[i][j] = i * n + j + 1;
				dfs(i, j, i, j, 1, map[i][j], i * n + j + 1);
			}
		}
	}
	if (res == 1) printf("Yes\n");
	else printf("No\n");
	return 0;
}
