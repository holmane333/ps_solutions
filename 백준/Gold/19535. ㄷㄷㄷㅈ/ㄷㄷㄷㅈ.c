#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int* tree[400000];
int treesize[400000], data[400000][2], idx;

long long int Return_w(long long int n) {
	return (n * (n - 1) * (n - 2)) < 0 ? LLONG_MAX : (n * (n - 1) * (n - 2)) / 6LL;
}

int main() {
	int n, u, v;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		tree[u] = realloc(tree[u], (treesize[u] + 1) * sizeof(int));
		tree[u][treesize[u]++] = v;
		tree[v] = realloc(tree[v], (treesize[v] + 1) * sizeof(int));
		tree[v][treesize[v]++] = u;
		data[idx][0] = v;
		data[idx++][1] = u;
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 0; j < treesize[i]; j++) {
			printf("%d ", tree[i][j]);
		}
		puts("");
	}*/
	long long int ddd = 0, w = 0;
	for (int i = 0; i < n - 1; i++) {
		ddd += (treesize[data[i][0]] - 1) * (treesize[data[i][1]] - 1);
	}
	for (int i = 1; i <= n; i++) {
		if (treesize[i] >= 3) w = Return_w((long long)treesize[i]) == LLONG_MAX ? LLONG_MAX : w + Return_w((long long)treesize[i]);
		if (w < 0) {
			w = LLONG_MAX;
			break;
		}
	}
	if (ddd == w * 3LL) printf("DUDUDUNGA\n");
	else if (ddd > w * 3LL) printf("D\n");
	else printf("G\n");
	return 0;
}