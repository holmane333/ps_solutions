#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node{
	long long data, lazy;
}node;

int n, m, k, c;
long long ary[2000002], ary2[2000002], depth[2000002];
node seg_tree[2097154];
int* adj[1000001];
int len[1000001], S[1000001], E[1000001], cnt = 0;

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node].data = ary2[start];
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	seg_tree[node].data = seg_tree[node * 2].data + seg_tree[node * 2 + 1].data;
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg_tree[node].data = seg_tree[node].data + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

void rangeupdate(int node, int start, int end, int left, int right, long long diff) {
	if (seg_tree[node].lazy != 0) {
		seg_tree[node].data += seg_tree[node].lazy * (end - start + 1);
		if (start != end) {
			seg_tree[node * 2].lazy += seg_tree[node].lazy;
			seg_tree[node * 2 + 1].lazy += seg_tree[node].lazy;
		}
		seg_tree[node].lazy = 0;
	}
	if (right < start || left > end) return;
	else if (left <= start && end <= right) {
		seg_tree[node].data += diff * (end - start + 1);
		if (start != end) {
			seg_tree[node * 2].lazy += diff;
			seg_tree[node * 2 + 1].lazy += diff;
		}
	}
	else {
		rangeupdate(node * 2, start, (start + end) / 2, left, right, diff);
		rangeupdate(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
		seg_tree[node].data = seg_tree[node * 2].data + seg_tree[node * 2 + 1].data;
	}
}
 
long long sum(int node, int start, int end, int left, int right) {
	if (seg_tree[node].lazy != 0) {
		seg_tree[node].data += seg_tree[node].lazy * (end - start + 1);
		if (start != end) {
			seg_tree[node * 2].lazy += seg_tree[node].lazy;
			seg_tree[node * 2 + 1].lazy += seg_tree[node].lazy;
		}
		seg_tree[node].lazy = 0;
	}
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return seg_tree[node].data;
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void dfs(int now, int prev) {
	S[now] = ++cnt;
	for (int i = 0; i < len[now]; ++i) {
		if (depth[adj[now][i]] == 0) {
			depth[adj[now][i]] = depth[now] + 1;
			dfs(adj[now][i], now);
		}
	}
	E[now] = cnt;
}

int main(void) {
	scanf("%d %d", &n, &c);
	for (int i = 0; i <= n; ++i) adj[i] = malloc(sizeof(int));
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		++len[a];
		++len[b];
		adj[a] = realloc(adj[a], sizeof(int) * len[a]);
		adj[b] = realloc(adj[b], sizeof(int) * len[b]);
		adj[a][len[a] - 1] = b;
		adj[b][len[b] - 1] = a;
	}
	//for (int i = 0; i <= n; i++) printf("%d -> %d\n", i, sizeof(adj[i]));
	/*for (int i = 0; i <= n; i++) {
		printf("%d: ", i);
		for (int j = 0; j < len[i]; ++j) printf("%d ", adj[i][j]); puts("");
	}*/
	depth[c] = 1;
	dfs(c, -1);
	//for (int i = 1; i <= n; ++i) printf("%d ", depth[i]); puts("");
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			rangeupdate(1, 1, n, S[b], S[b], 1);
		}
		else {
			printf("%lld\n", sum(1, 1, n, S[b], E[b]) * depth[b]);
		}
	}
	for (int i = 0; i <= n; ++i) free(adj[i]);
	
	return 0;
}
