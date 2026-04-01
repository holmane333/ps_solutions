#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define mod 1000000000

typedef struct node {
	int a, b, w;
} node;

int n, m;
long long cost, s[1000001];
int parent[1000001];
node ary[1000001];

int cmp(const void* num1, const void* num2) {
	return (*(node*)num2).w - (*(node*)num1).w;
}

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	parent[a] = b;
	s[b] += s[a];
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) 
		parent[i] = i, s[i] = 1;
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &(ary[i].a), &(ary[i].b), &(ary[i].w));
		cost += (long long)ary[i].w;
	}
	qsort(ary + 1, m, sizeof(node), cmp);
	long long res = 0LL;
	for (int i = 1; i <= m; ++i) {
		int a = getParent(ary[i].a);
		int b = getParent(ary[i].b);
		int w = ary[i].w;
		
		//printf("%d %d %lld %lld %lld %lld\n", a, b, s[a], s[b], s[a] * s[b], res);
		if (a != b) {
			res += (((s[a] * s[b]) % mod) * cost) % mod;
			res %= mod;
			unionFind(a, b);
		}
		cost -= (long long)w;
	}
	printf("%lld\n", res);
	return 0;
}
