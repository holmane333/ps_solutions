#include <stdio.h>
#include <memory.h>
#include <limits.h>
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#pragma warning(disable:4996)

int visit[101][101], visit_copy[101][101], map[101][101], n;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int t) {
	visit[x][y] = t;
	for (int i = 0; i < 4; i++) {
		int rx = x + dx[i];
		int ry = y + dy[i];
		if (rx >= 0 && rx < n && ry >= 0 && ry < n && map[rx][ry] == 1 && visit[rx][ry] == 0) {
			dfs(rx, ry, t);
		}
	}
}

int bfs(int x, int y) {
	int t = visit[x][y];
	int q[20001][2], ft = 0, rr = 0;
	q[ft][0] = x;
	q[ft++][1] = y;
	q[ft][0] = -1;
	q[ft++][1] = -1;
	int cnt = 0, stack = 0;
	while(ft != rr) {
		int sx = q[rr][0];
		int sy = q[rr++][1];
		if (rr >= 20000) rr = 0;
		if (sx == -1 && sy == -1) {
			cnt++;
			if (stack == 1) return INT_MAX;
			stack++;
			q[ft][0] = -1;
			q[ft++][1] = -1;
			if (ft >= 20000) ft = 0;
			continue;
		}
		stack = 0;
		for (int i = 0; i < 4; i++) {
			int rx = sx + dx[i];
			int ry = sy + dy[i];
			if (rx >= 0 && rx < n && ry >= 0 && ry < n) {
				if (map[rx][ry] == 0 && visit[rx][ry] == 0) {
					q[ft][0] = rx;
					q[ft++][1] = ry;
					if (ft >= 20000) ft = 0;
					visit[rx][ry] = -1;
				}
				else if (map[rx][ry] == 1 && visit[rx][ry] != t) return cnt;
			}
		}
	}
	
	return INT_MAX;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) dfs(i, j, cnt++);
		}
	}
	
	memcpy(visit_copy, visit, sizeof(visit));
	int res = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				int data = bfs(i, j);
				res = res > data ? data : res;
				memcpy(visit, visit_copy, sizeof(visit));
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
