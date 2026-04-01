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
	int t;
}pair;

int n, m, max = 0;
char map[51][51];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };

void bfs(int y, int x) {
	int check[51][51];
	memset(check, 0, sizeof(check));
	check[y][x] = 1;
	pair newi = { y, x, 0 };
	pair queue[20000];
	int ft = 0, nr = 0;
	queue[ft++] = newi;

	while (ft != nr) {
		pair curr = queue[nr++];
		nr %= 20000;
		max = max > curr.t ? max : curr.t;
		for (int i = 0; i < 4; i++) {
			int cy = curr.y + dy[i];
			int cx = curr.x + dx[i];
			if (cx >= 0 && cx < m && cy >= 0 && cy < n && !check[cy][cx] && map[cy][cx] == 'L') {
				pair new1 = { cy, cx, curr.t + 1 };
				queue[ft++] = new1;
				ft %= 20000;
				check[cy][cx] = 1;
			}
		}
	}
	
}

int main() {
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
		}
		getchar();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') bfs(i, j);
		}
	}

	printf("%d\n", max);

	return 0;
}