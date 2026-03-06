#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, res = 0;
int map[50][50];

void move(int i) {
	int stack[500], top = 0;
	switch (i) {
		case 1: // left
			for (int i = 1; i <= n; ++i) {
				top = 0;
				for (int j = 1; j <= n; ++j) {
					if (map[i][j] != 0) stack[top++] = map[i][j];
					map[i][j] = 0;
				}
				int idx = 1, check = 0;
				for (int j = 0; j < top; ++j) {
					if (map[i][idx - 1] == stack[j] && check == 0) {
						map[i][idx - 1] <<= 1;
						check = 1;
					}
					else {
						map[i][idx++] = stack[j];
						check = 0;
					}
				}
			}
			break;
		case 2: // right
			for (int i = 1; i <= n; ++i) {
				top = 0;
				for (int j = n; j >= 1; --j) {
					if (map[i][j] != 0) stack[top++] = map[i][j];
					map[i][j] = 0;
				}
				int idx = n, check = 0;
				for (int j = 0; j < top; ++j) {
					if (map[i][idx + 1] == stack[j] && check == 0) {
						map[i][idx + 1] <<= 1;
						check = 1;
					}
					else {
						map[i][idx--] = stack[j];
						check = 0;
					}
				}
			}
			break;
		case 3: // up
			for (int j = 1; j <= n; ++j) {
				top = 0;
				for (int i = 1; i <= n; ++i) {
					if (map[i][j] != 0) stack[top++] = map[i][j];
					map[i][j] = 0;
				}
				int idx = 1, check = 0;
				for (int i = 0; i < top; ++i) {
					if (map[idx - 1][j] == stack[i] && check == 0) {
						map[idx - 1][j] <<= 1;
						check = 1;
					}
					else {
						map[idx++][j] = stack[i];
						check = 0;
					}
				}
			}
			break;
		default: // down
			for (int j = 1; j <= n; ++j) {
				top = 0;
				for (int i = n; i >= 1; --i) {
					if (map[i][j] != 0) stack[top++] = map[i][j];
					map[i][j] = 0;
				}
				int idx = n, check = 0;
				for (int i = 0; i < top; ++i) {
					if (map[idx + 1][j] == stack[i] && check == 0) {
						map[idx + 1][j] <<= 1;
						check = 1;
					}
					else {
						map[idx--][j] = stack[i];
						check = 0;
					}
				}
			}
			break;
	}
}

void dfs(int idx) {
	if (idx == 5) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				res = max(res, map[i][j]);
		return;
	}
	int cpy_map[50][50];
	memcpy(cpy_map, map, sizeof(int) * 50 * 50);
	for (int i = 1; i <= 4; ++i) {
		move(i);
		/*for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				printf("%d ", map[i][j]);
			}
			puts("");
		}
		puts("");*/
		dfs(idx + 1);
		memcpy(map, cpy_map, sizeof(int) * 50 * 50);
	}
	/*for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", cpy_map[i][j]);
		}
		puts("");
	}
	puts("");*/
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &map[i][j]);
	dfs(0);
	printf("%d\n", res);

	return 0;
}