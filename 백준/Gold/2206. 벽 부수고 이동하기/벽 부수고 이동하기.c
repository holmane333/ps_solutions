#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int arr[1001][1001];
int col, row, qft = 0, qbk = 0, qsize = 1;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int check[1001][1001][2], v[1001][1001][2];
int queue[1000001][3];

void bfs() {
	int x, y, z;
	while (qsize) {
		x = queue[qft][0];
		y = queue[qft][1];
		z = queue[qft++][2];
		qft %= 1000001;
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];

			if (0 <= newx && newx < row && 0 <= newy && newy < col) {
				if (!arr[newy][newx] && !check[newy][newx][z] && !v[newy][newx][z]) {
					check[newy][newx][z] = check[y][x][z] + 1;
					queue[qbk][0] = newx;
					queue[qbk][1] = newy;
					queue[qbk++][2] = z;
					v[newy][newx][z] = 1;
					qbk %= 1000001;
				}
				else if (arr[newy][newx] && !check[newy][newx][1] && !v[newy][newx][1] && !z) {
					check[newy][newx][1] = check[y][x][0] + 1;
					queue[qbk][0] = newx;
					queue[qbk][1] = newy;
					queue[qbk++][2] = 1;
					v[newy][newx][1] = 1;
					qbk %= 1000001;
				}
			}

		}
		qsize = abs(qbk - qft);

	}
}

int main() {
	char t[1001];
	scanf("%d %d\n", &col, &row);
	for (int i = 0; i < col; i++) {
		scanf("%s", t);
		for (int j = 0; j < row; j++) {
			arr[i][j] = (int)t[j] - 48;
		}
	}
	queue[qbk][0] = 0;
	queue[qbk][1] = 0;
	queue[qbk++][2] = 0;
	check[0][0][0] = 1;
	v[0][0][0] = 1;
	

	bfs();
	/*
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%4d ", check[i][j][0]);
		}
		puts("");
	}puts("");
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%4d ", check[i][j][1]);
		}
		puts("");
	}puts("");
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%4d ", v[i][j][0]);
		}
		puts("");
	}puts("");
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%4d ", v[i][j][1]);
		}
		puts("");
	}puts("");
	*/

	if (check[col - 1][row - 1][0] || check[col - 1][row - 1][1]) printf("%d\n", check[col - 1][row - 1][1] != 0 ? check[col - 1][row - 1][1] : check[col - 1][row - 1][0]);
	else puts("-1");

	return 0;
}