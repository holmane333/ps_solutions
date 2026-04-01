#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

typedef struct boom{
	char t;
	int cnt;
}boom;

int n;
boom map[201][201], submap[201][201];
int dx[] = { -1,1,0,0,0 }, dy[] = { 0,0,-1,1,0 };

int main() {
	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);
	getchar();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c", &(map[i][j].t));
			map[i][j].cnt = 2;
		}
		getchar();
	}

	for (int k = 0; k < n - 1; k++) {
		memset(submap, 0, sizeof(submap));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j].t == '.') {
					if (submap[i][j].cnt != 2) {
						submap[i][j].t = 'O';
						submap[i][j].cnt = 1;
					}
				}
				else {
					if (map[i][j].cnt >= 3) {
						for (int l = 0; l < 5; l++) {
							int cy = i + dy[l];
							int cx = j + dx[l];
							if (cy >= 0 && cy < r && cx >= 0 && cx < c) {
								submap[cy][cx].t = '.';
								submap[cy][cx].cnt = 2;
							}
						}
					}
					else {
						if (submap[i][j].cnt != 2) {
							submap[i][j].t = 'O';
							submap[i][j].cnt = map[i][j].cnt + 1;
						}
					}
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				map[i][j] = submap[i][j];
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", map[i][j].t);
		}puts("");
	}puts("");
	return 0;
}
