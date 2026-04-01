#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node {
	int* a;
	int len;
} node;

int n, e;
int len[10010], ilen[10010];
int* dir[10010];
int* idir[10010];
node scc[10010];
int idx;
int s[20020], ft, v[10010];

int cmp(const void* a1, const void* b1) {
	return *(int*)a1 > *(int*)b1;
}

int cmp2(const void* a1, const void* b1) {
	node aa = *(node*)a1; 
	node bb = *(node*)b1;
	return aa.a[0] > bb.a[0];
}

void dfs(int i) {
	v[i] = 1;
	for (int j = 0; j < len[i]; ++j) {
		if (!v[dir[i][j]]) dfs(dir[i][j]);
	}
	s[ft++] = i;
}

void dfs2(int d, int idx) {
	v[d] = 1;
	scc[idx].a = (int*)realloc(scc[idx].a, sizeof(int) * (++scc[idx].len));
	scc[idx].a[scc[idx].len - 1] = d;
	for (int i = 0; i < ilen[d]; ++i) {
		if (!v[idir[d][i]]) dfs2(idir[d][i], idx);
	}
}

int main() {
	scanf("%d %d", &n, &e);
	for (int i = 0; i <= 10000; ++i) dir[i] = (int*)malloc(sizeof(int)), idir[i] = (int*)malloc(sizeof(int)), scc[i].a = (int*)malloc(sizeof(int));
	for (int i = 0; i < e; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		dir[a] = (int*)realloc(dir[a], sizeof(int) * (++len[a]));
		idir[b] = (int*)realloc(idir[b], sizeof(int) * (++ilen[b]));
		dir[a][len[a] - 1] = b;
		idir[b][ilen[b] - 1] = a;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!v[i]) dfs(i);
	}
	memset(v, 0, sizeof(v));
	for (int i = ft - 1; i >= 0; --i) {
		if (v[s[i]]) continue;
		dfs2(s[i], idx++);
	}
	for (int i = 0; i < idx; ++i) qsort(scc[i].a, scc[i].len, sizeof(int), cmp);
	qsort(scc, idx, sizeof(node), cmp2);
	printf("%d\n", idx);
	for (int i = 0; i < idx; ++i) {
		for (int j = 0; j < scc[i].len; ++j) {
			printf("%d ", scc[i].a[j]);
		}
		printf("-1\n");
	}
	return 0;
}