#include <stdio.h>
#pragma warning (disable:4996)

int n;
char map[110][110];
int dx[9] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[9] = {0, 0, 1, -1, 1, -1, 1, -1};

int main(void) {
	int tc;
	scanf("%d", &tc);
	
	while (tc--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", map[i] + 1);
		}
		if (n <= 2) {
			printf("0\n");
			continue;
		}
		/*for (int i = 1; i <= n; ++i) {
			printf("%s\n", map[i] + 1);
		}*/
		int a, b, c, t; // a: 주위에 놔둘 수 있는 공간, b: 폭탄 수, c: 폭탄 아닌 자리 수
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				t = (int)map[i][j] - '0';
				if (t == 0) {
					for (int k = 0; k < 8; ++k) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
						map[ii][jj] = 'X';
					}
					continue;
				}
				a = 0;
				b = 0;
				c = 0;
				if (t < 0 || t > 9) continue;
				for (int k = 0; k < 8; ++k) {
					int ii = i + dx[k];
					int jj = j + dy[k];
					if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
					++a;
					if (map[ii][jj] == 'O') ++b;
					if (map[ii][jj] == 'X') ++c;
				}
				//printf("%d %d %d %d %d %d\n", i, j, t, a, b, c);
				if (a == t) {
					for (int k = 0; k < 8; ++k) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
						map[ii][jj] = 'O';
					}
				}
				else if (a - c == t) {
					for (int k = 0; k < 8; ++k) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
						if (map[ii][jj] == '#') map[ii][jj] = 'O';
					}
				}
				else if (b == t) {
					for (int k = 0; k < 8; ++k) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
						if (map[ii][jj] == '#') map[ii][jj] = 'X';
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				t = (int)map[i][j] - '0';
				if (t == 0) {
					for (int k = 0; k < 8; ++k) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
						map[ii][jj] = 'X';
					}
					continue;
				}
				a = 0;
				b = 0;
				c = 0;
				if (t < 0 || t > 9) continue;
				for (int k = 0; k < 8; ++k) {
					int ii = i + dx[k];
					int jj = j + dy[k];
					if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
					++a;
					if (map[ii][jj] == 'O') ++b;
					if (map[ii][jj] == 'X') ++c;
				}
				//printf("%d %d %d %d %d %d\n", i, j, t, a, b, c);
				if (a == t) {
					for (int k = 0; k < 8; ++k) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
						map[ii][jj] = 'O';
					}
				}
				else if (a - b == t) {
					for (int k = 0; k < 8; ++k) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
						if (map[ii][jj] == '#') map[ii][jj] = 'O';
					}
				}
				else if (b == t) {
					for (int k = 0; k < 8; ++k) {
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii <= 1 || jj <= 1 || ii >= n || jj >= n) continue;
						if (map[ii][jj] == '#') map[ii][jj] = 'X';
					}
				}
			}
		}
		int res = 0;
		/*for (int i = 1; i <= n; ++i) {
			printf("%s\n", map[i] + 1);
		}*/
		for (int i = 2; i < n; ++i) {
			for (int j = 2; j < n; ++j) {
				if (map[i][j] == '#' || map[i][j] == 'O') ++res;
			}
		}
		printf("%d\n", res);
	}
	
	
	return 0;
}
