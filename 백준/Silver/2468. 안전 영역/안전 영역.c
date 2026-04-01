#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, max = INT_MIN, min = INT_MAX, cnt = 0;
int map[101][101], check[101][101];

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

void dfs(int y, int x, int k) {
	check[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (cy >= 0 && cy < n && cx >= 0 && cx < n && !check[cy][cx] && map[cy][cx] > k) {
			dfs(cy, cx, k);
		}
	}
	
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			max = max > map[i][j] ? max : map[i][j];
			min = min < map[i][j] ? min : map[i][j];
		}
	}
	int count = 0;
	if (max == min) cnt = 1;
	else {
		for (int k = min; k < max; k++) {
			count = 0;
			memset(check, 0, sizeof(check));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (!check[i][j] && map[i][j] > k) {
						count++;
						dfs(i, j, k);
					}
				}
			}
			cnt = cnt > count ? cnt : count;
		}
	}

	printf("%d\n", cnt);
	return 0;
}