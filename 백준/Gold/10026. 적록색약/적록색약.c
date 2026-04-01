#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int check[200][200];
int n;
char str[200][200];

int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

void BFS(int x, int y, char c, int tc) {
	check[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int c_x = x + dx[i];
		int c_y = y + dy[i];
		if (c_x >= 0 && c_x < n && c_y >= 0 && c_y < n && !check[c_y][c_x]) {
			switch (c)
			{
			case 'B':
				if (c == str[c_y][c_x]) BFS(c_x, c_y, c, tc);
				break;
			case 'R': case 'G':
				if (tc == 1) {
					if (c == str[c_y][c_x]) BFS(c_x, c_y, c, tc);
				}
				else {
					if (str[c_y][c_x] == 'R' || str[c_y][c_x] == 'G') BFS(c_x, c_y, c, tc);
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				cnt1++;
				check[i][j] = 1;
				BFS(j, i, str[i][j], 1);
			}
		}
	}
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				cnt2++;
				check[i][j] = 1;
				BFS(j, i, str[i][j], 2);
			}
		}
	}

	printf("%d %d\n", cnt1, cnt2);
	return 0;
}