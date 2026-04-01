#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define max_int 21
#define max_val 401


int n, a[max_int][max_int], check[max_int][max_int], ix, iy, eat_cnt, shark_size = 2;
int min_dist, min_x, min_y, result;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

typedef struct pair {
	int x, y;
} pair;

void init_check() {
	min_dist = max_val;
	min_x = max_int;
	min_y = max_int;

	memset(check, -1, sizeof(check));
}

void bfs(int x, int y) {
	pair q[500050];
	int ft = 0, rr = 0;
	check[x][y] = 0;
	q[rr].x = x;
	q[rr++].y = y;

	while (ft != rr) {
		pair cur = q[ft++];
		int x = cur.x;
		int y = cur.y;

		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];

			if (cx < 1 || cx > n || cy < 1 || cy > n) continue;
			if (check[cx][cy] != -1 || a[cx][cy] > shark_size) continue;

			check[cx][cy] = check[x][y] + 1;

			if (a[cx][cy] != 0 && a[cx][cy] < shark_size) {

				if (min_dist > check[cx][cy]) {
					min_x = cx;
					min_y = cy;
					min_dist = check[cx][cy];
				}
				else if (min_dist == check[cx][cy]) {
					if (min_x == cx) {
						if (min_y > cy) {
							min_x = cx;
							min_y = cy;
						}
					}
					else if (min_x > cx) {
						min_x = cx;
						min_y = cy;
					}
				}
			}

			q[rr].x = cx;
			q[rr++].y = cy;
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);

			if (a[i][j] == 9) {
				ix = i;
				iy = j;
				a[i][j] = 0;
			}
		}
	}

	while (1) {
		init_check();

		bfs(ix, iy);

		if (min_x != max_int && min_y != max_int) {
			result += check[min_x][min_y];

			eat_cnt++;

			if (eat_cnt == shark_size) {
				shark_size++;
				eat_cnt = 0;
			}

			a[min_x][min_y] = 0;

			ix = min_x;
			iy = min_y;
		}

		else {
			break;
		}
	}

	printf("%d\n", result);
}