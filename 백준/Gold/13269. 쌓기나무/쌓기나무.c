#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	int n, m, a[510][510], b[510], b1[510] = {0, }, c[510], c1[510] = {0, }, res[510][510];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = n - 1; i >= 0; --i) {
		scanf("%d", &c[i]);
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!a[i][j]) {
				res[i][j] = 0;
				continue;
			}
			res[i][j] = min(b[j], c[i]);
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (res[i][j] == b[j]) b1[j] = 1;
			if (res[i][j] == c[i]) c1[i] = 1;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (!c1[i]) {
			puts("-1");
			return 0;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		if (!b1[i]) {
			puts("-1");
			return 0;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", res[i][j]);
		}puts("");
	}
	
	return 0;
}
