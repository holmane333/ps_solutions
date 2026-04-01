#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)
#define max(a, b) (((a) > (b)) ? (a) : (b))

int n, check[201];
int ary[201][4];

int dfs(int cur) {
	check[cur] = 1;
	int cont = 1;
	int maxlen = ary[cur][2] * ary[cur][2];
	for (int i = 0; i < n; i++) {
		int len = (ary[cur][0] - ary[i][0]) * (ary[cur][0] - ary[i][0]) + (ary[cur][1] - ary[i][1]) * (ary[cur][1] - ary[i][1]);
		if (!check[i] && len <= maxlen) {
			cont += dfs(i);
		}
	}
	return cont;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &ary[i][0], &ary[i][1], &ary[i][2]);
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		int dfs_res = dfs(i);
		res = max(res, dfs_res);
	}
	printf("%d\n", res);
	return 0;
}
