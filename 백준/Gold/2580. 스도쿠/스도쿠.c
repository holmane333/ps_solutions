#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
 
int n;
int map[10][10];
int col[10][10], row[10][10], gridmap[10][10];
 
void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", map[i][j]);
			} puts("");
		} puts("");
		exit(0);
	}
 
	int x = cnt / 9, y = cnt % 9;
	if (map[x][y]) dfs(cnt + 1);
	else {
		for (int i = 1; i <= n; i++) {
			if (!col[x][i] && !row[y][i] && !gridmap[(x / 3) * 3 + y / 3][i]) {
				map[x][y] = i;
				col[x][i] = 1;
				row[y][i] = 1;
				gridmap[(x / 3) * 3 + y / 3][i] = 1;
				dfs(cnt + 1);
				map[x][y] = 0;
				col[x][i] = 0;
				row[y][i] = 0;
				gridmap[(x / 3) * 3 + y / 3][i] = 0;
			}
		}
	}
}
 
int main(void) {
	n = 9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) {
				col[i][map[i][j]] = 1;
				row[j][map[i][j]] = 1;
				gridmap[(i / 3) * 3 + j / 3][map[i][j]] = 1;
			}
		}
	}
	dfs(0);
 
 
	return 0;
}
 