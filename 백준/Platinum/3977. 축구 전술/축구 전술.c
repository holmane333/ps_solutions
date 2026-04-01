#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning (disable:4996)

typedef struct node {
	int* a;
	int len;
} node;

int n, e;
int len[100010], ilen[100010];
int* dir[100010];
int* idir[100010];
node scc[100010];
int sccn[100010];
int idx;
int s[300020], ft, v[100010];

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
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(len, 0, sizeof(len));
		memset(ilen, 0, sizeof(ilen));
		memset(sccn, 0, sizeof(sccn));
		memset(v, 0, sizeof(v));
		memset(s, 0, sizeof(s));
		idx = 0;
		ft = 0;
		scanf("%d %d", &n, &e);
		for (int i = 0; i <= 100001; ++i) dir[i] = (int*)malloc(sizeof(int)), idir[i] = (int*)malloc(sizeof(int)), scc[i].a = (int*)malloc(sizeof(int));
		for (int i = 0; i < e; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			++a;
			++b;
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
		
		for (int i = 0; i < idx; ++i) {
			for (int j = 0; j < scc[i].len; ++j) {
				sccn[scc[i].a[j]] = i + 1;
				//printf("%d ", scc[i].a[j]);
			}
			//puts("");
		}
		int c = 0, res = 0, t;
		for (int i = 0; i < idx; ++i) {
			c = 0;
			for (int j = 0; j < scc[i].len; ++j) {
				for (int k = 0; k < ilen[scc[i].a[j]]; ++k) {
					if (sccn[scc[i].a[j]] != sccn[idir[scc[i].a[j]][k]]) {
						c = 1;
						//printf(" %d, %d\n", sccn[scc[i].a[j]], sccn[idir[scc[i].a[j]][k]]);
					}
				}
			}
			if (!c) {
				if (res == 0) t = i;
				++res;
			}
		}
		
		//printf("%d\n", res);
		if (res >= 2) printf("Confused\n");
		else {
			for (int i = 0; i < scc[t].len; ++i) {
				printf("%d\n", scc[t].a[i] - 1);
			}
		}
		puts("");
		
		for (int i = 0; i <= 100001; ++i) free(dir[i]), free(idir[i]), free(scc[i].a), scc[i].len = 0;
	}
	return 0;
}