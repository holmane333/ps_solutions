#include <stdio.h>
#pragma warning(disable:4996)

int n, k;
int parent[1000001], q[5000001][4], visit[2010][2010], ft = 0, rr = 0;
int jo = 0;
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};

int abs(int a) {
	return a > 0 ? a : -a;
}

int distance(int a1, int b1, int a2, int b2) {
	return abs(a1 - a2) + abs(b1 - b2);
}

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	jo++;
	a = getParent(a);
	b = getParent(b);
	
	if (a > b) parent[b] = a;
	else parent[a] = b;
}

int bfs() {
	int cnt = 0, stack = 0;
	while (1) {
		if (jo == k - 1) break;
		if (ft == rr) break;
		int x = q[rr][0];
		int y = q[rr][1];
		int z = q[rr++][2];
		if (rr >= 5000000) rr = 0;
		if (x == -1 && y == -1 && z == -1) {
			q[ft][0] = -1;
			q[ft][1] = -1;
			q[ft++][2] = -1;
			if (ft >= 5000000) ft = 0;
			cnt++;
            stack++;
            if (stack >= 2) break;
			continue;
		}
        stack = 0;
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx <= 0 || cy <= 0 || cx > n || cy > n || visit[cx][cy]) continue;
			visit[cx][cy] = z;
			for (int j = 0; j < 4; j++) {
				int ccx = cx + dx[j];
				int ccy = cy + dy[j];
				if (ccx <= 0 || ccy <= 0 || ccx > n || ccy > n || !visit[ccx][ccy]) continue;
				if (getParent(visit[ccx][ccy]) != getParent(visit[cx][cy])) unionFind(visit[ccx][ccy], visit[cx][cy]);
			}
			q[ft][0] = cx;
			q[ft][1] = cy;
			q[ft++][2] = z;
			if (ft >= 5000000) ft = 0;
		}
	}
	
	return cnt;
}

int main(void) {
	scanf("%d %d", &n, &k);
	q[ft][0] = -1;
	q[ft][1] = -1;
	q[ft++][2] = -1;
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		q[ft][0] = a;
		q[ft][1] = b;
		q[ft++][2] = i + 1;
		visit[a][b] = i + 1;
		parent[i] = i;
	}
	parent[k] = k;
	for (int i = 0; i < ft; i++) {
		for (int j = 0; j < 4; j++) {
			int x = q[i][0] + dx[j];
			int y = q[i][1] + dy[j];
			if (x <= 0 || y <= 0 || x > n || y > n || !visit[x][y]) continue;
			if (getParent(visit[x][y]) != getParent(visit[q[i][0]][q[i][1]])) unionFind(visit[x][y], visit[q[i][0]][q[i][1]]);
		}
	}
	printf("%d\n", bfs());
	return 0;
}
