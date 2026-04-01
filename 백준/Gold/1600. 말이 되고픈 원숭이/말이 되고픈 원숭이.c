#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int v[210][210][50], q[400001][4], ft, rr, m[210][210], w, h, K;
int dxh[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dyh[8] = {2, 1, -1, -2, -2, -1, 1, 2}, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int bfs() {
	int minv = 1e9, x, y, t, k, cx, cy;
	q[ft][0] = 1;
	q[ft][1] = 1;
	q[ft][2] = 0;
	q[ft++][3] = K;
	v[1][1][K] = 0;
	while (ft != rr) {
		x = q[rr][0];
		y = q[rr][1];
		t = q[rr][2];
		k = q[rr++][3];
		if (x == h && y == w) minv = min(minv, t);
		//printf("%d %d %d %d\n", x, y, t, k);
		if (rr >= 400000) rr = 0;
		
		if (k >= 1) {
			for (int i = 0; i < 8; ++i) {
				cx = x + dxh[i];
				cy = y + dyh[i];
				if (cx <= 0 || cx > h || cy <= 0 || cy > w || m[cx][cy]) continue;
				if (v[cx][cy][k - 1] == -1 || v[cx][cy][k - 1] > t + 1) {
					v[cx][cy][k - 1] = t + 1;
					q[ft][0] = cx;
					q[ft][1] = cy;
					q[ft][2] = t + 1;
					q[ft++][3] = k - 1;
					if (ft >= 400000) ft = 0;
				}
			}
		}
		for (int i = 0; i < 4; ++i) {
			cx = x + dx[i];
			cy = y + dy[i];
			if (cx <= 0 || cx > h || cy <= 0 || cy > w || m[cx][cy]) continue;
			if (v[cx][cy][k] == -1 || v[cx][cy][k] > t + 1) {
				v[cx][cy][k] = t + 1;
				q[ft][0] = cx;
				q[ft][1] = cy;
				q[ft][2] = t + 1;
				q[ft++][3] = k;
				if (ft >= 400000) ft = 0;
			}
		}
	}
	return minv == 1e9 ? -1 : minv;
}

int main(void) {
	memset(v, -1, sizeof(v));
	scanf("%d", &K);
	scanf("%d %d", &w, &h);
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			scanf("%d", &m[i][j]);
		}
	}
	
	printf("%d\n", bfs());
	
	return 0;
}
