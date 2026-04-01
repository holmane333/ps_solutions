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
	int k;  //너구리: 1, water: 0, clk: 2
}pair;

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

int main() {
	int n, m, idx = 0, c = 0;
	char map[51][51];
	pair local, water[2501];
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'S') {
				local.y = i;
				local.x = j;
				local.k = 1;
			}
			else if (map[i][j] == '*') {
				water[idx].y = i;
				water[idx].x = j;
				water[idx++].k = 0;
			}
		}
		getchar();
	}
	
	pair queue[20000];
	int ft = 0, nr = 0;
	pair clock = { -1,-1,2 };
	queue[ft++] = clock;
	queue[ft++] = local;
	for (int i = 0; i < idx; i++) {
		queue[ft++] = water[i];
		ft %= 20000;
	}

	int cnt = 1, clk = 0;

	while (ft != nr) {
		if (cnt == 0) break;
		if (c == 1) break;
		pair curr = queue[nr++];
		nr %= 20000;
		if (curr.k == 2) {
			queue[ft++] = curr;
			ft %= 20000;
			clk++;
			continue;
		}
		if (curr.k == 1 && map[curr.y][curr.x] == '*') continue;
		for (int i = 0; i < 4; i++) {
			if (c == 1) break;
			int cy = curr.y + dy[i];
			int cx = curr.x + dx[i];
			if (cx >= 0 && cx < m && cy >= 0 && cy < n) {
				if (curr.k == 1 && (map[cy][cx] == '.' || map[cy][cx] == 'D')) {
					if (map[cy][cx] == 'D') {
						c = 1;
						break;
					}
					map[cy][cx] = 'S';
					pair new1 = { cy, cx, curr.k };
					queue[ft++] = new1;
					ft %= 20000;
					cnt++;
				}
				if (curr.k == 0 && (map[cy][cx] == '.' || map[cy][cx] == 'S')) {
					if (map[cy][cx] == 'S') cnt--;
					map[cy][cx] = '*';
					pair new1 = { cy, cx, curr.k };
					queue[ft++] = new1;
					ft %= 20000;
				}
			}
		}
	}

	if (c == 1) printf("%d\n", clk);
	else printf("KAKTUS\n");

	return 0;
}