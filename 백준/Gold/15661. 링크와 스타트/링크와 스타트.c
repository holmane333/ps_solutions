#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, map[101][101], check[101], res1[101], res2[101], res_cnt = INT_MAX;

void dfs(int t, int cnt) {
	if (cnt >= n) {
		int idx1 = 0, idx2 = 0, data1 = 0, data2 = 0;
		for (int i = 0; i < n; i++) {
			if (check[i] == 1) res1[idx1++] = i;
			else res2[idx2++] = i;
		}
		if (!idx1 || !idx2) return;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (i < idx1 && j < idx1) data1 += map[res1[i]][res1[j]];
				if (i < idx2 && j < idx2) data2 += map[res2[i]][res2[j]];
			}
		}
		res_cnt = res_cnt < abs(data1 - data2) ? res_cnt : abs(data1 - data2);
		return;
	}
	
	check[t + 1] = 1;
	dfs(t + 1, cnt + 1);
	check[t + 1] = 0;
	
	check[t + 1] = 2;
	dfs(t + 1, cnt + 1);
	check[t + 1] = 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	check[0] = 1;
	dfs(0, 1);
	check[0] = 0;
	check[0] = 2;
	dfs(0, 1);
	check[0] = 0;

	if (n == 1) res_cnt = 0;
	printf("%d\n", res_cnt);
	return 0;
}
