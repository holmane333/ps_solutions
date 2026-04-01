#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int x, y, v;
} node;

int cmp(const void* num1, const void* num2) {
	return (*(node*)num1).v < (*(node*)num2).v;
}

int parent[100010];

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	parent[b] = a;
}

int main(void) {
	int n, m, s, e;
	node d[100010];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &(d[i].x), &(d[i].y), &(d[i].v));
	}
	scanf("%d %d", &s, &e);
	qsort(d, m, sizeof(node), cmp);
	
	for (int i = 0; i <= n; ++i) parent[i] = i;
	for (int i = 0; i < m; ++i) {
		unionFind(d[i].x, d[i].y);
		if (getParent(s) == getParent(e)) {
			printf("%d\n", d[i].v);
			break;
		}
	}
	
	return 0;
}
