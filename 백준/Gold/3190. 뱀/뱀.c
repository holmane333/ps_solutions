#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct element {
	int t;
	char c;
}element;

typedef struct pair {
	int y;
	int x;
	int d;  //0은 북쪽, 1은 동쪽, 2는 남쪽, 3은 서쪽
}pair;

int dx[] = { 0,1,0,-1 }, dy[] = { -1,0,1,0 };

int main() {
	int n, k, check[200][200], y, x, l, t;
	char c;
	scanf("%d\n%d", &n, &k);
	memset(check, 0, sizeof(check));
	check[1][1] = 1;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &y, &x);
		check[y][x] = 2;
	}
	scanf("%d", &l);
	element data[200];
	int idx = 0, first = 0;
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &t, &c);
		element p1 = { t,c };
		data[idx++] = p1;
		getchar();
	}
	pair queue[10001];
	int ft = 0, nr = 0;
	pair header = { 1, 1, 1 };
	queue[ft++] = header;
	int cnt = 0, mark = 0;
	while (ft != nr) {

		cnt++;
		int c_x = header.x + dx[header.d];
		int c_y = header.y + dy[header.d];

		if (c_x > 0 && c_x <= n && c_y > 0 && c_y <= n && check[c_y][c_x] != 1) {
			pair new1 = { c_y, c_x, header.d };
			header.x = c_x;
			header.y = c_y;
			queue[ft++] = new1;
			if (check[c_y][c_x] == 2) mark = 1;
			check[c_y][c_x] = 1;
		}
		else break;

		if (mark == 0) {
			pair curr = queue[nr++];
			check[curr.y][curr.x] = 0;
		}
		else mark = 0;

		for (int i = first; i < idx; i++) {
			if (cnt == data[i].t) {
				first++;
				switch (data[i].c)
				{
				case 'D':
					header.d = (header.d + 1) % 4;
					break;
				case 'L':
					header.d = (header.d + 3) % 4;
				}
			}
			else break;
		}
		
	}
	printf("%d\n", cnt);
	return 0;
}