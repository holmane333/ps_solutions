#include <stdio.h>
#pragma warning(disable:4996)

int n;
char ary[52][52];
int v[52][52][2], dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1}; //0: 세로, 1: 가로

void bfs(int sx, int sy, int ss) {
	v[sx][sy][ss] = 1;
	int q[10010][3], ft = 0, rr = 0;
	q[ft][0] = sx;
	q[ft][1] = sy;
	q[ft++][2] = ss;
	
	while (ft != rr) {
		int x = q[rr][0], y = q[rr][1], s = q[rr][2];
		if (++rr > 10000) rr = 0;
		
		for (int i = 0; i < 4; ++i) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 1 || cx > n || cy < 1 || cy > n || ary[cx][cy] == '1') continue;
			if (!v[cx][cy][s] || v[cx][cy][s] > v[x][y][s] + 1) {
				if ((s == 0 && ary[cx - 1][cy] == '0' && ary[cx + 1][cy] == '0') || (s == 1 && ary[cx][cy - 1] == '0' && ary[cx][cy + 1] == '0')) {
					v[cx][cy][s] = v[x][y][s] + 1;
					q[ft][0] = cx;
					q[ft][1] = cy;
					q[ft++][2] = s;
					if (ft > 10000) ft = 0;
				}
			}
		}
		if (v[x][y][!s] && v[x][y][!s] < v[x][y][s] + 1) continue;
		if (x - 1 < 1 || x + 1 > n || y - 1 < 1 || y + 1 > n) continue;
		int c = 0;
		for (int i = x - 1; i <= x + 1; ++i) {
			for (int j = y - 1; j <= y + 1; ++j) {
				if (ary[i][j] == '1') c = 1;
			}
		}
		if (!c) {
			v[x][y][!s] = v[x][y][s] + 1;
			q[ft][0] = x;
			q[ft][1] = y;
			q[ft++][2] = !s;
			if (ft > 10000) ft = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", ary[i] + 1);
	}
	
	int sx = -1, sy = -1, ss = -1, ex = -1, ey = -1, es = -1;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (ary[i][j] == 'B' && sx == -1) {
				if ((ary[i - 1][j] == 'B' && ary[i + 1][j] == 'B') || (ary[i][j - 1] == 'B' && ary[i][j + 1] == 'B')) {
					sx = i;
					sy = j;
					if (ary[i - 1][j] == 'B') ss = 0;
					else ss = 1;
				}
				else if (ary[i - 1][j] == 'B') {
					sx = i - 1;
					sy = j;
					ss = 0;
				}
				else if (ary[i + 1][j] == 'B') {
					sx = i + 1;
					sy = j;
					ss = 0;
				}
				else if (ary[i][j - 1] == 'B') {
					sx = i;
					sy = j - 1;
					ss = 1;
				}
				else {
					sx = i;
					sy = j + 1;
					ss = 1;
				}
			}
			if (ary[i][j] == 'E' && ex == -1) {
				if ((ary[i - 1][j] == 'E' && ary[i + 1][j] == 'E') || (ary[i][j - 1] == 'E' && ary[i][j + 1] == 'E')) {
					ex = i;
					ey = j;
					if (ary[i - 1][j] == 'E') es = 0;
					else es = 1;
				}
				else if (ary[i - 1][j] == 'E') {
					ex = i - 1;
					ey = j;
					es = 0;
				}
				else if (ary[i + 1][j] == 'E') {
					ex = i + 1;
					ey = j;
					es = 0;
				}
				else if (ary[i][j - 1] == 'E') {
					ex = i;
					ey = j - 1;
					es = 1;
				}
				else {
					ex = i;
					ey = j + 1;
					es = 1;
				}
			}
			if (ary[i][j] == 'B' || ary[i][j] == 'E') ary[i][j] = '0';
		}
	}
	
	bfs(sx, sy, ss);
	
	printf("%d\n", !v[ex][ey][es] ? v[ex][ey][es] : v[ex][ey][es] - 1);
	return 0;
}