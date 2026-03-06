#include <stdio.h>
#include <stdlib.h>

int n, m, ary[20], res[20];

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; ++i) printf("%d ", res[i]);
		puts("");
		return;
	}
	
	for (int i = 0; i < n; ++i) {
		res[cnt] = ary[i];
		dfs(cnt + 1);
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ary[i]);
	}
	qsort(ary, n, sizeof(int), cmp);
	dfs(0);
	return 0;
}
