#pragma warning(disable:4996)
#include<stdio.h>

int parent[1000001];

int getParent(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = getParent(parent[a]);
}

int unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) {
		if (a < b)
			parent[b] = a;
		else parent[a] = b;
		return 0;
	}
	return 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;
	
	for (int i = 0; i < m; i++) {
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		if (t == 0) {
			unionFind(a, b);
		}
		else {
			if (getParent(a) == getParent(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;

}