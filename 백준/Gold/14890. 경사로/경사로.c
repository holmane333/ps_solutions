#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>

int main(void) {
	int n, l, res = 1, cnt = 0;
	int a[110][110], c[110][110] = {0, };
	scanf("%d %d", &n, &l);
	memset(a, -1, sizeof(a));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		res = 1;
		for (int j = 1; j < n; ++j) {
			if (!res) break;
			if (a[i][j] == a[i][j + 1] - 1) {
				//printf("%d %d\n", a[i][j], a[i][j + 1]);
				if (c[i][j]) {
					res = 0;
					break;
				}
				c[i][j] = 1;
				for (int k = 1; k <= l - 1; ++k) {
					if (j - k <= 0) {
						res = 0;
						break;
					}
					if (a[i][j] == a[i][j - k] && !c[i][j - k]) {
						c[i][j - k] = 1;
					}
					else res = 0;
				}
			}
			else if (a[i][j] == a[i][j + 1] + 1) {
				//printf("%d %d\n", a[i][j], a[i][j + 1]);
				c[i][j + 1] = 1;
				for (int k = 1; k <= l - 1; ++k) {
					if (j + 1 + k > n) {
						res = 0;
						break;
					}
					if (a[i][j + 1] == a[i][j + 1 + k]) {
						c[i][j + 1 + k] = 1;
					}
					else res = 0;
				}
			}
			else if (a[i][j] == a[i][j + 1]) continue;
			else res = 0;
		}
		//puts("");
		if (res) ++cnt;
		//if (res) printf("%d\n", i);
	}
	//puts("");
	memset(c, 0, sizeof(c));
	for (int j = 1; j <= n; ++j) {
		res = 1;
		for (int i = 1; i < n; ++i) {
			if (!res) break;
			if (a[i][j] == a[i + 1][j] - 1) {
				if (c[i][j]) {
					res = 0;
					break;
				}
				c[i][j] = 1;
				for (int k = 1; k <= l - 1; ++k) {
					if (i - k <= 0) {
						res = 0;
						break;
					}
					if (a[i][j] == a[i - k][j] && !c[i - k][j]) {
						c[i - k][j] = 1;
					}
					else res = 0;
				}
			}
			else if (a[i][j] == a[i + 1][j] + 1) {
				c[i + 1][j] = 1;
				for (int k = 1; k <= l - 1; ++k) {
					if (i + 1 + k > n) {
						res = 0;
						break;
					}
					if (a[i + 1][j] == a[i + 1 + k][j]) {
						c[i + 1 + k][j] = 1;
					}
					else res = 0;
				}
			}
			else if (a[i][j] == a[i + 1][j]) continue;
			else res = 0;
		}
		if (res) ++cnt;
		//if (res) printf("%d\n", j);
	}
	
	printf("%d\n", cnt);
	return 0;
}
