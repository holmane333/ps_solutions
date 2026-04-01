#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, m, data[101][101], check[101], res[101], cnt, res_cnt;

void dfs(int v, int t, int d) {
	if (cnt >= (n + 1) / 2) {
		if (!res[v]) res_cnt++;
		res[v] = 1;
		return;
	}
	check[t] = 1;
	
	for (int i = 1; i <= n; i++) {
		if (d == 0) {
			if (data[t][i] && !check[i]) {
				cnt++;
				dfs(v, i, d);
			}
		}
		else {
			if (data[i][t] && !check[i]) {
				cnt++;
				dfs(v, i, d);
			}
		}
	}
}

int main() {
	int y, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &y, &x);
		data[y][x] = 1;
	}

	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		cnt = 0;
		dfs(i, i, 1);
		memset(check, 0, sizeof(check));
		cnt = 0;
		dfs(i, i, 0);
	}

	printf("%d\n", res_cnt);
	return 0;
}
