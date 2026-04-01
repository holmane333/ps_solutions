#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int parent[1000001];

int getParent(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) {
		if (a < b)
			parent[b] = a;
		else parent[a] = b;
	}
}

int main() {
	int g, p, cnt = 0;
	scanf("%d %d", &g, &p);
	for (int i = 1; i <= g; i++) parent[i] = i;
	for (int i = 1; i <= p; i++) {
		int k, t;
		scanf("%d", &k);
		if (t = getParent(k)) {
			unionFind(t, t - 1);
			cnt++;
		}
		else break;
	}
	
	printf("%d\n", cnt);
	return 0;
}