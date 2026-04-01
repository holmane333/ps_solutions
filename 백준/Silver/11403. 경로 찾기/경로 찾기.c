#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n;
int map[101][101], check[101];

void dfs(int s, int f) {
	for (int i = 0; i < n; i++) {
		if (i == f) continue;
		if (map[f][i] && !check[i]) {
			map[s][i] = 1;
			check[i] = 1;
			dfs(s, i);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		dfs(i, i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		puts("");
	}
	puts("");

	return 0;
}