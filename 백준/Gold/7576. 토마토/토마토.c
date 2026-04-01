#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int arr[1001][1001];
int col, row, qft = 0, qbk = 0, qsize = 1, count = 1;
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
int check[1001][1001], v[1001][1001];
int queue[10000001][3];

void bfs() {
	int x, y;
	qsize = abs(qbk - qft);
	while (qsize) {
		x = queue[qft][1];
		y = queue[qft++][0];
		qft %= 1000001;
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (0 <= newx && newx < row && 0 <= newy && newy < col && !arr[newy][newx] && !check[newy][newx] && !v[newy][newx]) {
				check[newy][newx] = check[y][x] + 1;
				queue[qbk][0] = newy;
				queue[qbk++][1] = newx;
				v[newy][newx] = 1;
				qbk %= 1000001;
				count = check[newy][newx];
			}
		}
		qsize = abs(qbk - qft);

	}
}

int main() {
	scanf("%d %d", &row, &col);
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				queue[qbk][0] = i;
				queue[qbk++][1] = j;
				check[i][j] = 1;
				v[i][j] = 1;
			}
			if (arr[i][j] == -1) v[i][j] = 1;
		}
	}
	bfs();
	int cnt = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] == 0 && v[i][j] != 1) cnt = 1;
		}
	}
	if (cnt == 1) printf("-1\n");
	else {
		printf("%d\n", count - 1);
	}
	return 0;
}