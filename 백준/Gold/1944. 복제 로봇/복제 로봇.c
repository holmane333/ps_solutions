#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)

typedef struct node {
	int x, y, value;
} node;

node e[140000];
int parent[300];
int map[60][60], n, k, key[300][3], idx, cnt, v[60][60], q[10010][3];
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};

int cmp(const void* num1, const void* num2) {
	node a = *(node*)num1;
	node b = *(node*)num2;
	if (a.value == b.value) {
		if (a.x == b.x) return a.y - b.y;
		return a.x - b.x;
	}
	return a.value - b.value;
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

int unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a != b) {
		parent[b] = a;
		return 1;
	}
	return 0;
}

void bfs(int ix, int iy) {
	v[ix][iy] = 1;
	int ft = 0, rr = 0;
	q[ft][0] = ix;
	q[ft++][1] = iy;
	
	while (ft != rr) {
		int x = q[rr][0];
		int y = q[rr++][1];
		if (rr >= 10000) rr = 0;
		for (int i = 0; i < 4; ++i) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 1 || cx > n || cy < 1 || cy > n || v[cx][cy] || !map[cx][cy]) continue;
			v[cx][cy] = v[x][y] + 1;
			q[ft][0] = cx;
			q[ft++][1] = cy;
			if (ft >= 10000) ft = 0;
			if (map[cx][cy] != 1) {
				e[idx].x = map[ix][iy];
				e[idx].y = map[cx][cy];
				e[idx++].value = v[cx][cy];
				//printf("%d %d %d\n", e[idx - 1].x, e[idx - 1].y, e[idx - 1].value);
				++cnt;
			}
		}
	}
}

int main(void) {
	char line[60];
	scanf("%d %d", &n, &k);
	int count = 2;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", line);
		for (int j = 0; j < n; ++j) {
			if (line[j] == '0') map[i][j + 1] = 1;
			else if (line[j] == '1') map[i][j + 1] = 0;
			else {
				key[count][0] = i;
				key[count][1] = j + 1;
				map[i][j + 1] = count++;
			}
		}
	}
	
	for (int i = 2; i < count; ++i) {
		memset(v, 0, sizeof(v));
		cnt = 0;
		bfs(key[i][0], key[i][1]);
		if (cnt != k) {
			//printf("%d %d\n", cnt, k);
			printf("-1\n");
			return 0;
		}
	}
	
	qsort(e, idx, sizeof(node), cmp);
	
	cnt = 0;
	int res = 0;
	for (int i = 0; i < 300; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < idx; ++i) {
		if (cnt == k) break;
		if (unionFind(e[i].x, e[i].y)) {
			++cnt;
			res += e[i].value;
		}
	}
	
	printf("%d\n", res - k);
	return 0;
}
