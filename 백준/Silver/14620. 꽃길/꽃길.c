#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>
#define min(x, y) ((x) > (y) ? (y) : (x))

int dx[5] = {1, -1, 0, 0, 0}, dy[5] = {0, 0, 1, -1, 0};

int main(void) {
	int n, a[11][11], m[11][11], res = 2e9;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	
	int x1, y1, x2, y2, x3, y3;
	for (int i = 0; i < n * n; ++i) {
		x1 = i / n;
		y1 = i % n;
		if (x1 == 0 || x1 >= n - 1 || y1 == 0 || y1 >= n - 1) continue;
		for (int j = i + 1; j < n * n; ++j) {
			x2 = j / n;
			y2 = j % n;
			if (x2 == 0 || x2 >= n - 1 || y2 == 0 || y2 >= n - 1) continue;
			for (int k = j + 1; k < n * n; ++k) {
				x3 = k / n;
				y3 = k % n;
				if (x3 == 0 || x3 >= n - 1 || y3 == 0 || y3 >= n - 1) continue;
				memset(m, 0, sizeof(m));
				int c = 0, idx = 0;
				for (int l = 0; l < 5; ++l) {
					int cx = x1 + dx[l];
					int cy = y1 + dy[l];
					if (m[cx][cy]) {
						c = 1;
						break;
					}
					m[cx][cy] = 1;
					idx += a[cx][cy];
				}
				for (int l = 0; l < 5; ++l) {
					int cx = x2 + dx[l];
					int cy = y2 + dy[l];
					if (m[cx][cy]) {
						c = 1;
						break;
					}
					m[cx][cy] = 1;
					idx += a[cx][cy];
				}
				for (int l = 0; l < 5; ++l) {
					int cx = x3 + dx[l];
					int cy = y3 + dy[l];
					if (m[cx][cy]) {
						c = 1;
						break;
					}
					m[cx][cy] = 1;
					idx += a[cx][cy];
				}
				if (c) continue;
				//printf("%d %d\n", res, idx);
				res = min(res, idx);
			}
		}
	}
	
	printf("%d\n", res);
	return 0;
}
