#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct element {
	int x;
	int y;
	int r;
}element;

int dx[] = { 0, 1, 0, -1 }, dy[] = { -1,0,1,0 };

int main() {
	int n, m, r, c, d, ary[51][51], res = 0;
	scanf("%d %d\n%d %d %d", &n, &m, &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ary[i][j]);
		}
	}
	element queue[50000];
	int ft = 0, nr = 0;
	element new1 = { c, r, d };
	queue[ft++] = new1;
	while (ft != nr) {
		int x = queue[nr].x;
		int y = queue[nr].y;
		int r = queue[nr++].r;
		if (ary[y][x] == 0) {
			ary[y][x] = 2;
			res++;
		}
		int mark = 0;
		for (int i = 0; i < 4; i++) {
			int dr = (r + (3 - i)) % 4;
			int dX = x + dx[dr];
			int dY = y + dy[dr];
			if (dX >= 0 && dX < m && dY >= 0 && dY < n) {
				if (!ary[dY][dX]) {
					element new2 = { dX, dY, dr };
					queue[ft++] = new2;
					mark = 1;
					break;
				}
			}
		}
		if (!mark) {
			int bx = x - dx[r];
			int by = y - dy[r];
			if ((bx >= 0 && bx < m && by >= 0 && by < n) && ary[by][bx] != 1) {
				element new2 = { bx, by, r };
				queue[ft++] = new2;
			}
			else break;
		}
	}

	printf("%d\n", res);

	return 0;
}