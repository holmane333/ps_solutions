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

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int n, m, map[101][101], cnt = 0, res = 0;
int check[101][101];
int c = 0, cnt_crt;

void bfs(int y, int x) {
	pair newi = { y, x };
	pair queue[20000];
	int ft = 0, nr = 0;
	queue[ft++] = newi;
	check[y][x] = 0;

	while (ft != nr) {
		pair curr = queue[nr++];
		nr %= 20000;
		for (int i = 0; i < 4; i++) {
			int cy = curr.y + dy[i];
			int cx = curr.x + dx[i];
			if (cx >= 0 && cx < m && cy >= 0 && cy < n && check[cy][cx] == -1) {
				if (map[cy][cx] == 0) {
					pair new1 = { cy, cx };
					queue[ft++] = new1;
					ft %= 20000;
					check[cy][cx] = 0;
				}
				else {
					check[cy][cx] = 1;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) cnt++;
		}
	}
	cnt_crt = cnt;
	while (cnt_crt) {
		cnt = cnt_crt;
		cnt_crt = 0;
		memset(check, -1, sizeof(check));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					if (map[i][j] == 1) check[i][j] = 1;   //1일 때 지워질 치즈, 0일 때 바닥, -1일 때 지워지지 않을 것들
					else if (check[i][j] == -1) bfs(i, j);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				switch (check[i][j]) {
				case 1: case 0:
					map[i][j] = 0;
					break;
				case -1:
					if (map[i][j] == 1) cnt_crt++;
				}
			}
		}

		res++;
	}
	
	printf("%d\n%d\n", res, cnt);



	return 0;
}