#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m;
int ary[10001], ary2[10001], res[10001], len[10001], visit[10001];

int cmp(const void* num1, const void* num2) {
	return *(int*)num1 - *(int*)num2;
}

void dfs(int x, int y) {
	if (y == m) {
		for (int i = 0; i < m; ++i) printf("%d ", res[i]); 
		puts("");
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (visit[i] < len[i]) {
			++visit[i];
			res[y] = ary[i];
			dfs(i, y + 1);
			--visit[i];
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ary2[i]);
	}
	qsort(ary2 + 1, n, sizeof(int), cmp);
	int prev = 0, idx = 0;
	for (int i = 1; i <= n; ++i) {
		if (prev == ary2[i]) ++len[idx];
		else {
			prev = ary2[i];
			len[++idx] = 1;
			ary[idx] = ary2[i];
		}
	}
	n = idx;
	dfs(1, 0);
	return 0;
}