#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int n, m, map1[100][100], map2[100][100], v[100][100];
int dx[5] = { 1, -1, 0, 0 }, dy[5] = { 0, 0, 1, -1 };

int dfs(int x, int y, int t1, int t2) {
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx > 0 && cy > 0 && cx <= n && cy <= m && !v[cx][cy] && map1[cx][cy] == t1) {
			if (map2[cx][cy] != t2) return 0;
			v[cx][cy] = 1;
			int t = dfs(cx, cy, t1, t2);
			if (t == 0) return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &map1[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &map2[i][j]);
		}
	}

	int res = 1, count = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!v[i][j]) {
				v[i][j] = 1;
				if (map1[i][j] != map2[i][j]) ++count;
				res = dfs(i, j, map1[i][j], map2[i][j]);
				if (!res) break;
			}
		}
		if (!res) break;
	}
	if (res && count <= 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
