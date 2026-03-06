#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, cnt = -1;
int ary[1001][1001];
int check[1001];
int queue[1001], qsize;

void dfs(int f) {
	cnt++;
	check[f] = 1;
	for (int i = 1; i <= n; i++) {
		if (ary[f][i] && !check[i]) dfs(i);
	}
	return;
}


int main() {
	int k, a, b;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		ary[a][b] = 1;
		ary[b][a] = 1;
	}
	dfs(1);
	printf("%d\n", cnt);
	return 0;
}
