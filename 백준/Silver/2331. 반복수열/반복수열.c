#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, p;
int visit[300030];

void dfs(int t) {
	int k = 0;
	while (t) {
		k += (int)pow(t % 10, p);
		t /= 10;
	}
	if (visit[k] == 2) return;
	++visit[k];
	dfs(k);
}

int main(void) {
	scanf("%d %d", &n, &p);
	visit[n] = 1;
	dfs(n);
	int cnt = 0;
	for (int i = 0; i < 300030; ++i) {
		if (visit[i] == 1) ++cnt;
	}
	printf("%d\n", cnt);
	return 0;
}
