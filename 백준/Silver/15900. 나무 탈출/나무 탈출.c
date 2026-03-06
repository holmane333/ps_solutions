#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int* tree[500002];
int treesize[500002], n, check[500002], res = 0;

void bfs(int t, int cnt) {
	int count = 0;
	check[t] = 1;
	for (int i = 0; i < treesize[t]; i++) {
		if (!check[tree[t][i]]) {
			bfs(tree[t][i], cnt + 1);
			count++;
		}
	}
	if (count == 0) res += cnt;
	
}

int main() {
	scanf("%d", &n);
	int p, c;
	for (int i = 1; i <= n; i++) {
		tree[i] = (int*)malloc(sizeof(int));
		tree[i][0] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &p, &c);
		tree[p] = realloc(tree[p], sizeof(int) * (treesize[p] + 1));
		tree[p][treesize[p]] = c;
		treesize[p]++;
		tree[c] = realloc(tree[c], sizeof(int) * (treesize[c] + 1));
		tree[c][treesize[c]] = p;
		treesize[c]++;
	}
	bfs(1, 0);

	if (res % 2) printf("Yes\n");
	else printf("No\n");
	return 0;
}
