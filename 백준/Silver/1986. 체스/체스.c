#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int map[1010][1010];
int count = 0;
int n, m, num1;
int x, y;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1}, dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &num1);
	for (int i = 0; i < num1; ++i) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
	}
	scanf("%d", &num1);
	for (int i = 0; i < num1; ++i) {
		scanf("%d %d", &x, &y);
		map[x][y] = 2;
	}
	scanf("%d", &num1);
	for (int i = 0; i < num1; ++i) {
		scanf("%d %d", &x, &y);
		map[x][y] = 3;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (map[i][j] == 1) {
				for (int k = i + 1; k <= n; ++k) {
					if (map[k][j] == 0 || map[k][j] == 4) map[k][j] = 4;
					else break;
				}
				
				for (int k = i - 1; k >= 1; --k) {
					if (map[k][j] == 0 || map[k][j] == 4) map[k][j] = 4;
					else break;
				}
				
				for (int k = j + 1; k <= m; ++k) {
					if (map[i][k] == 0 || map[i][k] == 4) map[i][k] = 4;
					else break;
				}
				
				for (int k = j - 1; k >= 1; --k) {
					if (map[i][k] == 0 || map[i][k] == 4) map[i][k] = 4;
					else break;
				}
				
				for (int k = 1;; ++k) {
					if (i + k > n || j + k > m) break;
					if (map[i + k][j + k] == 0 || map[i + k][j + k] == 4) map[i + k][j + k] = 4;
					else break;
				}
				
				for (int k = 1;; ++k) {
					if (i - k < 1 || j - k < 1) break;
					if (map[i - k][j - k] == 0 || map[i - k][j - k] == 4) map[i - k][j - k] = 4;
					else break;
				}
				
				for (int k = 1;; ++k) {
					if (i + k > n || j - k < 1) break;
					if (map[i + k][j - k] == 0 || map[i + k][j - k] == 4) map[i + k][j - k] = 4;
					else break;
				}
				
				for (int k = 1;; ++k) {
					if (i - k < 1 || j + k > m) break;
					if (map[i - k][j + k] == 0 || map[i - k][j + k] == 4) map[i - k][j + k] = 4;
					else break;
				}
			}
			else if (map[i][j] == 2) {
				for (int k = 0; k < 8; ++k) {
					int cx = i + dx[k];
					int cy = j + dy[k];
					if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
					if (map[cx][cy] == 0) map[cx][cy] = 4;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!map[i][j]) ++count;
		}
	}
	
	printf("%d\n", count);
	return 0;
}