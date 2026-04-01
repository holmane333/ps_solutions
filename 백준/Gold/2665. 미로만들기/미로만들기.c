#include <stdio.h>

int n;
char s[60][60];
int v[60][60], dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};

void bfs() {
	int q[10010][2], ft = 0, rr = 0;
	q[rr][0] = 0;
	q[rr++][1] = 0;
	
	v[0][0] = 1;
	
	while(ft != rr) {
		int x = q[ft][0];
		int y = q[ft++][1];
		if (ft >= 10000) ft = 0;
		
		for (int i = 0; i < 4; ++i) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 0 || cy < 0 || cx >= n || cy >= n) continue;
			if (s[cx][cy] == '0' && (!v[cx][cy] || v[cx][cy] > v[x][y] + 1)) {
				v[cx][cy] = v[x][y] + 1;
				q[rr][0] = cx;
				q[rr++][1] = cy;
				if (rr >= 10000) rr = 0;
			}
			else if (s[cx][cy] == '1' && (!v[cx][cy] || v[cx][cy] > v[x][y])) {
				v[cx][cy] = v[x][y];
				q[rr][0] = cx;
				q[rr++][1] = cy;
				if (rr >= 10000) rr = 0;
			}
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
	}
	bfs();
	
	printf("%d\n", v[n - 1][n - 1] - 1);
	return 0;
}
