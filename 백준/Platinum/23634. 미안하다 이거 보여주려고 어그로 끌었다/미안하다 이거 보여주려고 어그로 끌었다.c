#include <stdio.h>
#pragma warning(disable:4996)

int n, m, k, fire = 0;
int map[2010][2010];
int parent[4002010], s[4002010], q[4002010][4], visit[2010][2010], ft = 0, rr = 0;
int jo = 0, res_jo = 0, res_cnt = 0, res_fire = 0;
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
	//printf("%d %d ", a, b);
	jo++;
	a = getParent(a);
	b = getParent(b);
	
	if (a > b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

void dfs(int x, int y) {
	++fire;
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx <= 0 || cy <= 0 || cx > n || cy > m || visit[cx][cy] || map[cx][cy] != 0) continue;
		visit[cx][cy] = visit[x][y];
		q[ft][0] = cx;
		q[ft][1] = cy;
		q[ft++][2] = visit[x][y];
		dfs(cx, cy);
	}
}

void bfs() {
	int cnt = 0, stack = 0;
	while (1) {
		if (ft == rr) break;
		int x = q[rr][0];
		int y = q[rr][1];
		int z = q[rr++][2];
		if (rr >= 4002000) rr = 0;
		if (x == -1 && y == -1 && z == -1) {
			if (res_jo != jo) {
				res_jo = jo;
				res_cnt = cnt;
				res_fire = fire;
			}
			q[ft][0] = -1;
			q[ft][1] = -1;
			q[ft++][2] = -1;
			if (ft >= 4002000) ft = 0;
			cnt++;
            stack++;
            if (stack >= 2) break;
			continue;
		}
        stack = 0;
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx <= 0 || cy <= 0 || cx > n || cy > m || visit[cx][cy] || map[cx][cy] == 2) continue;
			visit[cx][cy] = z;
			++fire;
			for (int j = 0; j < 4; j++) {
				int ccx = cx + dx[j];
				int ccy = cy + dy[j];
				if (ccx <= 0 || ccy <= 0 || ccx > n || ccy > m || !visit[ccx][ccy] || map[ccx][ccy] == 2) continue;
				if (getParent(visit[ccx][ccy]) != getParent(visit[cx][cy])) unionFind(visit[ccx][ccy], visit[cx][cy]);
			}
			q[ft][0] = cx;
			q[ft][1] = cy;
			q[ft++][2] = z;
			if (ft >= 4002000) ft = 0;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	q[ft][0] = -1;
	q[ft][1] = -1;
	q[ft++][2] = -1;
	for (int i = 1; i <= n; ++i) {
		char str[2010];
		scanf("%s", str + 1);
		for (int j = 1; j <= m; ++j) {
			map[i][j] = (int)str[j] - 48;
		}
	}
	int c = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!visit[i][j] && map[i][j] == 0) {
				parent[k] = k;
				q[ft][0] = i;
				q[ft][1] = j;
				q[ft++][2] = ++k;
				visit[i][j] = k;
				dfs(i, j);
				c = 1;
				//printf("%d %d\n", k, s[k]);
			}
		}
	}
	parent[k] = k;
	//puts("");
	/*
	for (int i = 0; i < ft; i++) {
		for (int j = 0; j < 4; j++) {
			int x = q[i][0] + dx[j];
			int y = q[i][1] + dy[j];
			if (x <= 0 || y <= 0 || x > n || y > m || !visit[x][y]) continue;
			if (getParent(visit[x][y]) != getParent(visit[q[i][0]][q[i][1]])) unionFind(visit[x][y], visit[q[i][0]][q[i][1]]);
		}
	}
	*/
	if (c == 0) printf("0 0\n");
	else {
		res_fire = fire;
		bfs();
		printf("%d %d\n", res_cnt, res_fire);
	}
	return 0;
}
