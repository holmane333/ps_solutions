#include <stdio.h>
#pragma warning(disable:4996)

int map[10][10], check[10][10], visit[100], con_visited[10][10], res, con_cnt;
int dx[5] = { 1, 0, -1, 0 }, dy[5] = { 0, 1, 0, -1 };

void dfs(int s, int n, int cnt) {
	if (cnt == 7) {
		if (count_s(s)) {
			con_cnt = 0;
			memset(con_visited, 0, sizeof(con_visited));
			con_visited[s / 5][s % 5] = 1;
			if (connected(s / 5, s % 5)) {
				res++;
			}
		}
	}
	else {
		for (int i = n + 1; i < 25; i++) {
			visit[i] = 1;
			check[i/5][i%5] = 1;
			dfs(s, i, cnt + 1);
			visit[i] = 0;
			check[i/5][i%5] = 0;
		}
	}
	
}

int count_s(int n) {
	int cnt = 0;
	for (int i = 0; i < 25; i++) {
		if (visit[i]) {
			if (map[i/5][i%5]) cnt++;
		}
	}
	if (cnt >= 4) return 1;
	return 0;
}

int connected(int x, int y) {
	con_cnt++;
	if (con_cnt == 7) return 1;
	else {
		for (int i = 0; i < 4; i++) {
			int sx = dx[i] + x;
			int sy = dy[i] + y;
			if (sx < 0 || sx > 4 || sy < 0 || sy > 4) continue;
			if (check[sx][sy] && !con_visited[sx][sy]) {
				con_visited[sx][sy] = 1;
				if (connected(sx, sy) == 1) return 1;
			}
		}
	}
	return 0;
}

int main(void) {
	char input[10];
	for (int i = 0; i < 5; i++) {
		scanf("%s", input);
		for (int j = 0; j < 5; j++) {
			if (input[j] == 'S') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	for (int i = 0; i < 25; i++) {
		visit[i] = 1;
		check[i/5][i%5] = 1;
		dfs(i, i, 1);
		visit[i] = 0;
		check[i/5][i%5] = 0;
		
	}
	
	printf("%d\n", res);
	
	return 0;
}
