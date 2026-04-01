#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, m;
int parent[1000001], v[1000001];

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	parent[a] = b;
}

int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; ++i) parent[i] = i;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!v[a]) {
			v[a] = 1;
			unionFind(a, b);
		}
		else if (!v[b]) {
			v[b] = 1;
			unionFind(b, a);
		}
		else if (!v[getParent(a)]) {
			v[getParent(a)] = 1;
			unionFind(a, b);
		}
		else if (!v[getParent(b)]) {
			v[getParent(b)] = 1;
			unionFind(b, a);
		}
		else {
			printf("SMECE\n");
			continue;
		}
		printf("LADICA\n");
	}
	
	return 0;
}
