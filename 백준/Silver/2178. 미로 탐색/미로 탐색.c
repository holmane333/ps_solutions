#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int arr[101][101];
int col, row;
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
int check[101][101], v[101][101];
int queue[1000001][3];

void bfs(int x1, int y1) {
	v[x1][y1] = 1;
	int x, y, qft = 0, qbk = 1, qsize = 0, cnt = 1;
	queue[qsize][0] = x1;
	queue[qsize++][1] = y1;
	while (qsize) {
		x = queue[qft][1];
		y = queue[qft][0];
		queue[qft][0] = 0;
		queue[qft++][1] = 0;
		qft %= 1000001;
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (0 <= newx && newx < row && 0 <= newy && newy < col && arr[newy][newx] && !check[newy][newx] && !v[newy][newx]) {
				check[newy][newx] = check[y][x] + 1;
				queue[qbk][0] = newy;
				queue[qbk++][1] = newx;
				v[newy][newx] = 1;
				qbk %= 1000001;
			}
		}
		qsize = abs(qbk - qft);

	}
}

int main() {
	char str[101];
	scanf("%d %d", &col,&row);
	for (int i = 0; i < col; i++) {
		scanf("%s", &str);
		for (int j = 0; j < row; j++) {
			arr[i][j] = (int)str[j] - 48;
		}
	}
	bfs(0, 0);
	printf("%d\n", check[col - 1][row - 1] + 1);
	return 0;
}