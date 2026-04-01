#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, m;
int c[1002], parent[1002];

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a == b || c[a] || c[b]) {
		c[a] = 1;
		c[b] = 1;
	}
	parent[b] = a;
}

int main(void) {
	int tc = 0;
	while(1) {
		scanf("%d %d", &n, &m);
		if (!n && !m) break;
		for (int i = 1; i <= n; ++i) parent[i] = i, c[i] = 0;
		int res = 0;
		for (int i = 1; i <= m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a != b) unionFind(a, b);
		}
		/*for (int i = 1; i <= n; ++i) printf("%d ", getParent(i));
		puts("");
		for (int i = 1; i <= n; ++i) printf("%d ", c[i]);
		puts("");*/
		for (int i = 1; i <= n; ++i) {
			int p = getParent(i);
			if (!c[p]) c[p] = 1, ++res;
		}
		printf("Case %d: ", ++tc);
		if (!res) printf("No trees.\n");
		else if (res == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", res);
	}
	
	return 0;
}
