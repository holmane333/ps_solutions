#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int max = INT_MIN;
int n, m, ary[600][600], check[600][600];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int shape1[4][2] = { {0, 0}, {1, 0}, {0, 0}, {0, 1} };
int shape2[4][2] = { {0, 1}, {0, 1}, {1, 0}, {1, 0} };
int shape3[4][2] = { {1, 1}, {1, 1}, {1, 1}, {1, 1} };
int shape4[4][2] = { {0, 2}, {1, 2}, {2, 0}, {2, 1} }; // x,y

void DFS(int cnt, int val, int x, int y) {
	if (cnt == 3) {
		max = max > val ? max : val;
		//if (max == val) printf("%d %d %d\n", x, y, max);
		return;
	}
	check[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int da = x + dx[i];
		int db = y + dy[i];
		if (da >= 0 && da < m && db >= 0 && db < n && !check[db][da]) {
			DFS(cnt + 1, val + ary[db][da], da, db);
		}
	}
	check[y][x] = 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ary[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			DFS(0, ary[i][j], j, i);
			for (int k = 0; k < 2; k++) {
				int res = 0;
				if (i + 2 < n || j + 1 < m) {
					res += ary[i + shape1[k][1]][j + shape1[k][0]];
					res += ary[i + shape2[k][1]][j + shape2[k][0]];
					res += ary[i + shape3[k][1]][j + shape3[k][0]];
					res += ary[i + shape4[k][1]][j + shape4[k][0]];
				}
				max = max > res ? max : res;
				//if (max == res) printf("%d %d %d %d", j, i, k, max);
			}
			for (int k = 2; k < 4; k++) {
				int res = 0;
				if (i + 1 < n || j + 2 < m) {
					res += ary[i + shape1[k][1]][j + shape1[k][0]];
					res += ary[i + shape2[k][1]][j + shape2[k][0]];
					res += ary[i + shape3[k][1]][j + shape3[k][0]];
					res += ary[i + shape4[k][1]][j + shape4[k][0]];
				}
				max = max > res ? max : res;
				//if (max == res) printf("%d %d %d %d", j, i, k, max);
			}
		}
		for (int j = 0; j < m; j++) {
			check[i][j] = 1;
		}
	}

	printf("%d\n", max);


	return 0;
}