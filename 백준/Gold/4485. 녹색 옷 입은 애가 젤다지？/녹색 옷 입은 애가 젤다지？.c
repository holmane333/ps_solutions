#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, ary[130][130], v[130][130];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int bfs() {
	int q[100001][3], ft = 0, rr = 0;
	q[ft][0] = 1;
	q[ft][1] = 1;
	q[ft++][2] = ary[1][1];
	v[1][1] = ary[1][1];
	
	while (ft != rr) {
		int x = q[rr][0];
		int y = q[rr][1];
		int z = q[rr++][2];
		if (rr >= 100000) rr = 0;
		
		for (int i = 0; i < 4; ++i) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 1 || cx > n || cy < 1 || cy > n) continue;
			if (!v[cx][cy] || v[cx][cy] > z + ary[cx][cy]) {
				v[cx][cy] = z + ary[cx][cy];
				q[ft][0] = cx;
				q[ft][1] = cy;
				q[ft++][2] = z + ary[cx][cy];
				if (ft >= 100000) ft = 0;
			}
		}
	}
	
	return v[n][n];
}

int main(void) {
	for (int i = 1;; ++i) {
		scanf("%d", &n);
		if (n == 0) break;
		memset(ary, 0, sizeof(ary));
		memset(v, 0, sizeof(v));
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				scanf("%d", &ary[j][k]);
			}
		}
		printf("Problem %d: %d\n", i, bfs());
	}
	
	return 0;
}
