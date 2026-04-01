#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))


typedef struct node {
	int left, right;
} node;

int n, v[10010];
int level_min[10010], level_max[10010];
node tree[10010];

int dfs(int idx, int cnt, int dep) {
	int now = cnt + 1, s = 0;
	if (tree[idx].left != -1) s += dfs(tree[idx].left, cnt, dep + 1);
	level_min[dep] = min(level_min[dep], now + s);
	level_max[dep] = max(level_max[dep], now + s);
	//printf("%d %d %d\n", idx, dep, now + s);
	if (tree[idx].right != -1) s += dfs(tree[idx].right, now + s, dep + 1);
	return s + 1;
}

int main(void) {
	int root = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int idx;
		scanf("%d", &idx);
		scanf("%d %d", &tree[idx].left, &tree[idx].right);
		if (tree[idx].left != -1) v[tree[idx].left] = 1;
		if (tree[idx].right != -1) v[tree[idx].right] = 1;
	}
	for (int i = 1; i <= 10000; ++i) {
		level_min[i] = 1e9;
		if (root == -1 && !v[i]) root = i;
	}
	dfs(root, 0, 1);
	
	int res = 0, d = 0;
	for (int i = 1; i <= n; ++i) {
		if (res < level_max[i] - level_min[i] + 1) {
			res = level_max[i] - level_min[i] + 1;
			d = i;
		}
	}
	printf("%d %d\n", d, res);
	return 0;
}
