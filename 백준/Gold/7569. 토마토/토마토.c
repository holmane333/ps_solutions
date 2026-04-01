#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int arr[101][101][101];
int col, row, h, qft = 0, qbk = 0, qsize = 1, count = 1;
int dx[6] = { 0,1,0,-1,0,0 }, dy[6] = { -1,0,1,0,0,0 }, dz[6] = { 0,0,0,0,1,-1 };
int check[101][101][101], v[101][101][101];
int queue[1000001][3];

void bfs() {
	int x, y, z;
	while (qsize) {
		x = queue[qft][2];
		y = queue[qft][1];
		z = queue[qft++][0];
		qft %= 1000001;
		for (int i = 0; i < 6; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			int newz = z + dz[i];
			if (0 <= newx && newx < row && 0 <= newy && newy < col && 0 <= newz && newz < h && !arr[newz][newy][newx] && !check[newz][newy][newx] && !v[newz][newy][newx]) {
				check[newz][newy][newx] = check[z][y][x] + 1;
				queue[qbk][2] = newx;
				queue[qbk][1] = newy;
				queue[qbk++][0] = newz;
				v[newz][newy][newx] = 1;
				qbk %= 1000001;
				count = check[newz][newy][newx];
			}
		}
		qsize = abs(qbk - qft);

	}
}

int main() {
	scanf("%d %d %d", &row, &col, &h);
	qsize = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			for (int k = 0; k < row; k++) {
				scanf("%d", &arr[i][j][k]);
				if (arr[i][j][k] == 1) {
					queue[qbk][0] = i;
					queue[qbk][1] = j;
					queue[qbk++][2] = k;
					check[i][j][k] = 1;
					v[i][j][k] = 1;
					qsize++;
				}
				if (arr[i][j][k] == -1) v[i][j][k] = 1;
			}
		}
	}

	bfs();
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			for (int k = 0; k < row; k++) {
				if (v[i][j][k] != 1) cnt = 1;
			}
		}
	}
	if (cnt == 1) printf("-1\n");
	else {
		printf("%d\n", count - 1);
	}
	return 0;
}