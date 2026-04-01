#include <stdio.h>

int n, m;
char map[1010][1010];
int v[1010][1010];
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, -1, 1};

int bfs(int s, int e, int s_l, int s_r) {
	int cnt = 1;
	int q[1000010][4], ft = 0, rr = 0;
	q[rr][0] = s;
	q[rr][1] = e;
	q[rr][2] = s_l;
	q[rr++][3] = s_r;
	
	while (ft != rr) {
		int x, y, l, r;
		x = q[ft][0];
		y = q[ft][1];
		l = q[ft][2];
		r = q[ft++][3];
		if (ft >= 1000010) ft = 0;
		//printf("%d %d %d %d\n", x, y, l, r);
		
		for (int i = 0; i < 2; ++i) {
			int cx = x + dx[i];
			int cy = y;
			
			while (cx >= 0 && cx < n) {
				if (map[cx][cy] == '1') break;
				if (!v[cx][cy]) {
					v[cx][cy] = 1;
					q[rr][0] = cx;
					q[rr][1] = cy;
					q[rr][2] = l;
					q[rr++][3] = r;
					if (rr >= 1000010) rr = 0;
					++cnt;
				}
				cx += dx[i];
			}
		}
		
		for (int i = 2; i < 4; ++i) {
			if (i == 2 && l == 0) continue;
			if (i == 3 && r == 0) continue;
			
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
			
			if (map[cx][cy] == '0' && !v[cx][cy]) {
				v[cx][cy] = 1;
				q[rr][0] = cx;
				q[rr][1] = cy;
				if (i == 2) q[rr][2] = l - 1;
				else q[rr][2] = l;
				if (i == 3) q[rr++][3] = r - 1;
				else q[rr++][3] = r;
				if (rr >= 1000010) rr = 0;
				++cnt;
			}
		}
	}
	
	
	return cnt;
}

int main(void) {
	scanf("%d %d", &n, &m);
	int l, r;
	scanf("%d %d", &l, &r);
	int s = -1, e = -1;
	
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
		if (s != -1) continue;
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '2') {
				s = i;
				e = j;
				break;
			}
		}
	}
	v[s][e] = 1;
	printf("%d\n", bfs(s, e, l, r));
	return 0;
}
