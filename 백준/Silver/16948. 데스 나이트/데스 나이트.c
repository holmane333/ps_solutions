#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

typedef struct pair{
	int y;
	int x;
	int cnt;
}pair;

int n;
int dx[] = { -1,1,2,-2,-1,1 }, dy[] = { -2,-2,0,0,2,2 }, check[201][201];

int bfs(int ys, int xs, int yf, int xf) {
	check[ys][xs] = 1;
	pair queue[40001];
	int ft = 0, nr = 0;
	pair newi = { ys,xs,0 };
	queue[ft++] = newi;
	
	while (ft != nr) {
		pair curr = queue[nr++];
		nr %= 40000;
		if (curr.y == yf && curr.x == xf) return curr.cnt;

		for (int i = 0; i < 6; i++) {
			int cy = curr.y + dy[i];
			int cx = curr.x + dx[i];
			if (cy >= 0 && cy < n && cx >= 0 && cx < n && !check[cy][cx]) {
				check[cy][cx] = 1;
				pair new1 = { cy,cx,curr.cnt + 1 };
				queue[ft++] = new1;
				ft %= 40000;
			}
		}
	}
	return -1;
}

int main() {
	int y1, x1, y2, x2;
	scanf("%d", &n);
	scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

	printf("%d\n", bfs(y1, x1, y2, x2));

	return 0;
}
