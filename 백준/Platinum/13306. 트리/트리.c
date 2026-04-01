#pragma warning(disable:4996)
#include<stdio.h>

int parent[1000001], ary[1000001][4], input[1000001];

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
	for (int i = 2; i <= n; i++) scanf("%d", &input[i]);
	
	for (int i = 0; i < n - 1 + m; i++) {
		scanf("%d", &ary[i][0]);
		if (ary[i][0] == 0) {
			scanf("%d", &ary[i][1]);
		}
		else {
			scanf("%d %d", &ary[i][1], &ary[i][2]);
		}
	}
	char* res[1000001];
	int idx = 0;

	for (int i = n - 1 + m - 1; i >= 0; i--) {
		int t = ary[i][0], a = ary[i][1], b = ary[i][2];
		if (t == 0) {
			unionFind(input[a], a);
		}
		else {
			if (getParent(a) == getParent(b)) res[idx++] = "YES\0";
			else res[idx++] = "NO\0";
		}
	}
	for (int i = idx - 1; i >= 0; i--) {
		printf("%s\n", res[i]);
	}
	return 0;
}