#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m;
int ary[10001], res[10001], visit[10001];

int cmp(const void* num1, const void* num2) {
	return *(int*)num1 - *(int*)num2;
}

void dfs(int y) {
	if (y == m) {
		for (int i = 0; i < m; ++i) printf("%d ", res[i]); 
		puts("");
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			res[y] = ary[i];
			dfs(y + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ary[i]);
	}
	qsort(ary + 1, n, sizeof(int), cmp);
	dfs(0);
	return 0;
}