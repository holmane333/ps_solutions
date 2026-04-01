#include <stdio.h>
#pragma warning(diable:4996)

int n, m;
int ary[200001], len[200001], res[200001];
int* adj[200001];

void dfs(int x, int cnt) {
	cnt += ary[x];
	res[x] = cnt;
	for (int i = 0; i < len[x]; ++i) {
		dfs(adj[x][i], cnt);
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; ++i) adj[i] = malloc(sizeof(int));
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a == -1) continue;
		++len[a];
		adj[a] = realloc(adj[a], sizeof(int) * len[a]);
		adj[a][len[a] - 1] = i;
	}
	
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ary[a] += b;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) printf("%d ", res[i]); puts("");
	return 0;
}
