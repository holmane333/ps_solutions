#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, m;
int parent[1000001], d[1000001];

int abs(int a) {
	return a > 0 ? a : -a;
}

int getParent(int a) {
	if (a == parent[a]) return a;
	int p = getParent(parent[a]);
	d[a] += d[parent[a]];
	return parent[a] = p;
}

void unionFind(int a, int b, int w) {
	int ra = getParent(a);
	int rb = getParent(b);
	
	if (ra == rb) return;
	d[rb] = d[a] - d[b] + w;
	parent[rb] = ra;
}

int main(void) {
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; ++i) parent[i] = i;
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= m; ++i) {
			char a[3];
			scanf("%s", a);
			if (a[0] == '!') {
				int b, c, d;
				scanf("%d %d %d", &b, &c, &d);
				unionFind(b, c, d);
			}
			else {
				int b, c;
				scanf("%d %d", &b, &c);
				if (getParent(b) == getParent(c)) printf("%d\n", d[c] - d[b]);
				else printf("UNKNOWN\n");
			}
			/*for (int i = 1; i <= n; ++i) printf("%d ", getParent(i));
			puts("");
			for (int i = 1; i <= n; ++i) printf("%d ", d[i]);
			puts("");*/
		}
	}
	return 0;
}
