#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n;
int map[1002][1002], visit[1002];

void dfs(int v) {
	visit[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[v][i] && !visit[i]) dfs(i);
	}
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}