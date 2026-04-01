//14499
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <memory.h>
#pragma warning(disable:4996)

int dice[4][4];
int map[20][20];
// 동쪽 = 1, 서쪽 = 2, 북쪽 = 3, 남쪽 = 4
int main()
{
	int my, mx, y, x, k, data;
	scanf("%d %d %d %d %d", &my, &mx, &y, &x, &k);
	for (int i = 0; i < my; i++) {
		for (int j = 0; j < mx; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &data);
		int tmp;
		switch (data)
		{
		case 1:
			if (x + 1 >= mx) break;
			tmp = dice[1][0];
			for (int j = 0; j < 3; j++) {
				dice[1][j % 4] = dice[1][(j + 1) % 4];
			}
			dice[1][3] = tmp; dice[3][1] = tmp;
			x++;
			if (map[y][x] != 0) {
				dice[1][1] = map[y][x];
				map[y][x] = 0;
			}
			else
				map[y][x] = dice[1][1];
			printf("%d\n", dice[1][3]);
			break;
		case 2:
			if (x - 1 <= -1) break;
			tmp = dice[1][3];
			for (int j = 2; j >= 0; j--) {
				dice[1][(j + 1) % 4] = dice[1][j % 4];
			}
			dice[1][0] = tmp; dice[3][1] = dice[1][3];
			x--;
			if (map[y][x] != 0) {
				dice[1][1] = map[y][x];
				map[y][x] = 0;
			}
			else
				map[y][x] = dice[1][1];
			printf("%d\n", dice[1][3]);
			break;
		case 3:
			if (y - 1 <= -1) break;
			tmp = dice[3][1];
			for (int j = 2; j >= 0; j--) {
				dice[(j + 1) % 4][1] = dice[j % 4][1];
			}
			dice[0][1] = tmp; dice[1][3] = dice[3][1];
			y--;
			if (map[y][x] != 0) {
				dice[1][1] = map[y][x];
				map[y][x] = 0;
			}
			else
				map[y][x] = dice[1][1];
			printf("%d\n", dice[1][3]);
			break;
		case 4:
			if (y + 1 >= my) break;
			tmp = dice[0][1];
			for (int j = 0; j < 3; j++) {
				dice[j % 4][1] = dice[(j + 1) % 4][1];
			}
			dice[3][1] = tmp; dice[1][3] = dice[3][1];
			y++;
			if (map[y][x] != 0) {
				dice[1][1] = map[y][x];
				map[y][x] = 0;
			}
			else
				map[y][x] = dice[1][1];
			printf("%d\n", dice[1][3]);
			break;
		}
		/*
		printf("%d %d %d\n", y, x,map[y][x]);
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				printf("%d ", dice[a][b]);
			}
			puts("");
		}
		puts("");
		*/
	}


	return 0;
}
