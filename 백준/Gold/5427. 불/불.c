#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

char map[1001][1001];
int h, w, tc;
int q[1000001][3], ft, rr, per_num, stack;
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};

int bfs() {
	int x, y, t, count = 1;
	stack = 0;
	while (ft != rr) {
		if (per_num <= 0) {
			return -1;
		}
		x = q[ft][0];
		y = q[ft][1];
		t = q[ft++][2];
		if (ft >= 1000000) ft = 0;
		if (t == 1 && map[x][y] != '@') {
			continue;
		}
		if (x == -1) {
			if (stack == 1) return -1;
			stack = 1;
			count++;
			q[rr][0] = -1;
			q[rr][1] = -1;
			q[rr++][2] = -1;
			if (rr >= 1000000) rr = 0;
			continue;
		}
		stack = 0;
		for (int i = 0; i < 4; i++) {
			int sx = x + dx[i];
			int sy = y + dy[i];
			if (sx < 0 || sx >= h || sy < 0 || sy >= w) {
				if (t) return count;
				continue;
			}
			if (map[sx][sy] == '#') continue;
			else if (map[sx][sy] == '.') {
				q[rr][0] = sx;
				q[rr][1] = sy;
				if (t) {
					map[sx][sy] = '@';
					q[rr++][2] = 1;
					++per_num;
				}
				else {
					map[sx][sy] =  '*';
					q[rr++][2] = 0;
				}
				if (rr >= 1000000) rr = 0;
			}
			else if (map[sx][sy] == '@' && !t) {
				map[sx][sy] = '*';
				q[rr][0] = sx;
				q[rr][1] = sy;
				q[rr++][2] = 0;
				if (rr >= 1000000) rr = 0;
				--per_num;
			}
			else continue;
		}
		/*for (int i = 0; i < h; i++) {
				printf("%s\n", map[i]);
		}puts("");*/
	}
	return count;
}

int main(void) {
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		memset(q, 0, sizeof(q));
		ft = 0; rr = 0;
		per_num = 0;
		scanf("%d %d", &w, &h);
		for (int i = 0; i < h; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '@') {
					q[rr][0] = i;
					q[rr][1] = j;
					q[rr++][2] = 1;
					per_num++;
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '*') {
					q[rr][0] = i;
					q[rr][1] = j;
					q[rr++][2] = 0;
				}
			}
		}
		q[rr][0] = -1;
		q[rr][1] = -1;
		q[rr++][2] = -1;
		int res = bfs();
		if (res == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", res);
	}
	
	return 0;
}
