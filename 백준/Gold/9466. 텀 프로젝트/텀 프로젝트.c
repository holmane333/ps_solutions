#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int check[100001], visit[100001], dir[100001], count;

void dfs(int i, int cnt, int v) {
	visit[i] = cnt;
	check[i] = v;
	if (!visit[dir[i]]) dfs(dir[i], cnt + 1, v);
	else if (v != check[dir[i]]) return;
	else count += cnt - visit[dir[i]] + 1;
	return;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		int n, cnt = 1;
		scanf("%d", &n);
		count = 0;
		memset(check, 0, sizeof(check));
		memset(visit, 0, sizeof(visit));
		memset(dir, 0, sizeof(dir));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &dir[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) dfs(i, 1, cnt++);
		}/*
		for (int i = 1; i <= n; i++) {
			printf("%d ", visit[i]);
		}puts("");
		for (int i = 1; i <= n; i++) {
			printf("%d ", check[i]);
		}puts("");*/
		printf("%d\n", n - count);
	}
	
	return 0;
}
