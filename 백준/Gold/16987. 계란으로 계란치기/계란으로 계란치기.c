#pragma warning(disable:4996)
#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, e[10][3], res, cnt;

void dfs(int idx) {
	//printf("%d\n", idx);
	if (idx >= n) {
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += (e[i][0] <= 0);
		}
		res = max(res, cnt);
		return;
	}
	if (e[idx][0] <= 0) dfs(idx + 1);
	else {
		int f = 0;
		for (int i = 0; i < n; ++i) {
			if (e[i][0] > 0 && i != idx) {
				f = 1;
				e[i][0] -= e[idx][1];
				e[idx][0] -= e[i][1];
				dfs(idx + 1);
				e[i][0] += e[idx][1];
				e[idx][0] += e[i][1];
			}
		}
		if (!f) dfs(idx + 1);
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &e[i][0], &e[i][1]);
	}
	dfs(0);
	
	printf("%d\n", res);
	return 0;
}
