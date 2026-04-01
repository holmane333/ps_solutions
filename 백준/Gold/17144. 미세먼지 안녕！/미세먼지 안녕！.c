#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct pair {
	int y1;
	int x1;
	int y2;
	int x2;
}pair;

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int ddx1[] = { 0, 1, 0, -1 }, ddy1[] = { -1, 0, 1, 0 };
int ddx2[] = { 0, 1, 0, -1 }, ddy2[] = { 1, 0, -1, 0 };

int main() {
	pair cleaner;
	int n, m, t, map[52][52], submap[52][52], c = 0;
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1 && c == 0) {
				cleaner.y1 = i;
				cleaner.x1 = j;
				cleaner.y2 = i + 1;
				cleaner.x2 = j;
				c = 1;
			}
		}
	}

	for (int tc = 0; tc < t; tc++) {
		memset(submap, 0, sizeof(submap));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int data = map[i][j] / 5;
				int cnt = 0;
				if (data == 0) continue;
				for (int k = 0; k < 4; k++) {
					int cy = i + dy[k];
					int cx = j + dx[k];
					if (cy >= 0 && cy < n && cx >= 0 && cx < m && map[cy][cx] != -1) {
						submap[cy][cx] += data;
						cnt++;
					}
				}
				submap[i][j] -= data * cnt;
			}
		}
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				map[i][j] += submap[i][j];

		int i = 0, y = cleaner.y1, x = cleaner.x1;
		while (1) {
			y += ddy1[i];
			x += ddx1[i];
			if (map[y][x] == -1) break;
			int cy = y + ddy1[i];
			int cx = x + ddx1[i];
			if (cy >= 0 && cy <= cleaner.y1 && cx >= 0 && cx < m) {
				if (map[cy][cx] == -1) {
					map[y][x] = 0;
					break;
				}
				else map[y][x] = map[cy][cx];
			}
			else {
				i++;
				cy = y + ddy1[i];
				cx = x + ddx1[i];
				map[y][x] = map[cy][cx];
			}
		}

		i = 0;
		y = cleaner.y2;
		x = cleaner.x2;
		while (1) {
			y += ddy2[i];
			x += ddx2[i];
			if (map[y][x] == -1) break;
			int cy = y + ddy2[i];
			int cx = x + ddx2[i];
			if (cy >= cleaner.y2 && cy < n && cx >= 0 && cx < m) {
				if (map[cy][cx] == -1) {
					map[y][x] = 0;
					break;
				}
				else map[y][x] = map[cy][cx];
			}
			else {
				i++;
				cy = y + ddy2[i];
				cx = x + ddx2[i];
				map[y][x] = map[cy][cx];
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] >= 1) cnt += map[i][j];
		}
	}

	printf("%d\n", cnt);

	return 0;
}