#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int visit[301][301], l;
int dx[9] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[9] = {2, -2, 1, -1, 2, -2, 1, -1};

int bfs(int ix, int iy, int ax, int ay) {
	int q[90002][3], rr = 0, ft = 0;
	q[ft][0] = ix;
	q[ft][1] = iy;
	q[ft++][2] = 0;
	visit[ix][iy] = 1;
	while (ft != rr) {
		int x = q[rr][0];
		int y = q[rr][1];
		int d = q[rr++][2];
		if (rr >= 90000) rr = 0;
		
		if (ax == x && ay == y) return d;
		
		for (int i = 0; i < 8; i++) {
			int rx = x + dx[i];
			int ry = y + dy[i];
			if (rx >= l || rx < 0 || ry >= l || ry < 0) continue;
			if (!visit[rx][ry]) {
				q[ft][0] = rx;
				q[ft][1] = ry;
				q[ft++][2] = d + 1;
				if (ft >= 90000) ft = 0;
				visit[rx][ry] = 1;
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		scanf("%d", &l);
		int ix, iy, ax, ay;
		memset(visit, 0, sizeof(visit));
		scanf("%d %d %d %d", &ix, &iy, &ax, &ay);
		printf("%d\n", bfs(ix, iy, ax, ay));
	}
	return 0;
}