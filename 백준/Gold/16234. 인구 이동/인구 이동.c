#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct pair {
	int y;
	int x;
}pair;

int check[51][51];
int map[51][51];
int n, l, r;

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

int bfs(int y, int x, int mark) {
	check[y][x] = mark;
	pair newi = { y,x };
	pair queue[20000];
	int ft = 0, nr = 0;
	queue[ft++] = newi;
	int total = map[y][x], c = 0;

	while (ft != nr) {
		pair curr = queue[nr++];
		nr %= 20000;
		for (int i = 0; i < 4; i++) {
			int cy = curr.y + dy[i];
			int cx = curr.x + dx[i];
			if (cx >= 0 && cx < n && cy >= 0 && cy < n && !check[cy][cx]) {
				int diff = abs(map[curr.y][curr.x] - map[cy][cx]);
				if (diff >= l && diff <= r) {
					check[cy][cx] = mark;
					pair new1 = { cy, cx };
					queue[ft++] = new1;
					ft %= 20000;
					c++;
					total += map[cy][cx];
				}
			}
		}
	}

	if (c == 0) {
		return -1;
	}
	else {
		return total / (c + 1);
	}


}

int main() {
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int res = 0;
	while (1) {
		int cnt = 1;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					int k = 0;
					k = bfs(i, j, cnt++);
					if (k != -1) {
						for (int i1 = 0; i1 < n; i1++) {
							for (int j1 = 0; j1 < n; j1++) {
								if (check[i1][j1] == cnt - 1) map[i1][j1] = k;
							}
						}
					}
				}
			}
		}
		if (check[n - 1][n - 1] == n * n) break;
		res++;
	}
	printf("%d\n", res);

	return 0;
}