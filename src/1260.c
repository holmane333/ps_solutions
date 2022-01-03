#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n;
int ary[1001][1001];
int check[1001];
int queue[1001], qsize;

void dfs(int f) {
	printf("%d ", f);
	check[f] = 1;
	for (int i = 1; i <= n; i++) {
		if (ary[f][i] && !check[i]) dfs(i);
	}
	return;
}

void bfs(int f) {
	int t, qft = 0, qbk = 1;
	check[f] = 1;
	queue[qsize++] = f;
	while (qsize) {
		t = queue[qft++];
		qft %= 1000;
		printf("%d ", t);
		for (int i = 1; i <= n; i++) {
			if (ary[t][i] && !check[i]) {
				check[i] = 1;
				queue[qbk++] = i;
				qbk %= 1000;
			}
		}
		qsize = abs(qbk - qft);

	}
}

int main() {
	int k, first, a, b;
	scanf("%d %d %d", &n, &k, &first);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		ary[a][b] = 1;
		ary[b][a] = 1;
	}
	dfs(first);
	puts("");
	memset(check, 0, sizeof(check));
	bfs(first);
	puts("");

	return 0;
}
