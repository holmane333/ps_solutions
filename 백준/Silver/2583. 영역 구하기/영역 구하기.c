#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, m, t, max = INT_MIN, min = INT_MAX, cnt = 0;
int map[101][101], check[101][101], ary[101], idx = 0;

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void dfs(int y, int x) {
	check[y][x] = 1;
	cnt++;
	
	for (int i = 0; i < 4; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (cy >= 0 && cy < n && cx >= 0 && cx < m && !check[cy][cx] && !map[cy][cx]) {
			dfs(cy, cx);
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &t);
	int x1, y1, x2, y2;
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int k = y1; k < y2; k++) {
			for (int l = x1; l < x2; l++) {
				map[k][l] = 1;
			}
		}
		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt = 0;
			if (!check[i][j] && !map[i][j]) dfs(i, j);
			if (cnt) ary[idx++] = cnt;
		}
	}

	qsort(ary, idx, sizeof(int), cmpfunc);

	printf("%d\n", idx);
	for (int i = 0; i < idx; i++) {
		printf("%d ", ary[i]);
	}
	return 0;
}
