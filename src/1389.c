#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, m;
int map[101][101], check[101], res[101][101];

void dfs(int k, int idx, int cnt) {
	res[idx][k] = res[idx][k] < cnt ? res[idx][k] : cnt;
	if (res[idx][k] == -1) res[idx][k] = cnt;

	for (int i = 1; i <= n; i++) {
		if (map[k][i] && !check[i]) {
			check[k] = 1;
			dfs(i, idx, cnt + 1);
			check[k] = 0;
		}
	}
}

int main() {
	int y, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &y, &x);
		map[y][x] = 1;
		map[x][y] = 1;
	}
	memset(res, -1, sizeof(res));
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		check[i] = 1;
		dfs(i, i, 0);
	}

	int idx = 1, min_cnt = INT_MAX;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (res[i][j] == -1) {
				cnt = INT_MAX;
				break;
			}
			cnt += res[i][j];
		}
		if (cnt < min_cnt) {
			idx = i;
			min_cnt = cnt;
		}
	}
	printf("%d\n", idx);

	return 0;
}
