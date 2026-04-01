#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int n, k, a, b;
int map[402][402], check[402];

void dfs(int s, int f) {
	for (int i = 1; i <= n; i++) {
		if (i == f) continue;
		if (map[f][i] && !check[i]) {
			map[s][i] = 1;
			check[i] = 1;
			dfs(s, i);
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		dfs(i, i);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &a, &b);
		if (map[a][b]) printf("-1\n");
		else if (map[b][a]) printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}