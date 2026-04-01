#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
 
int n, m;
int map[1002][3], map2[1002][3], dp[1002][1002];
 
int Abs(int a) {
	return a > 0 ? a : -a;
}
 
int dist(int map[][3], int i, int j) {
	return Abs(map[i][0] - map[j][0]) + Abs(map[i][1] - map[j][1]);
}
 
int DP(int i, int j, int x) {
	if (i == m || j == m) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	
	int a = DP(x, j, x + 1) + dist(map, i, x);
	int b = DP(i, x, x + 1) + dist(map2, j, x);
	dp[i][j] = min(a, b);
	return dp[i][j];
}

void path(int i, int j, int x) {
	if (i == m || j == m) return 0;
	
	int a = DP(x, j, x + 1) + dist(map, i, x);
	int b = DP(i, x, x + 1) + dist(map2, j, x);
	if (a > b) {
		printf("2\n");
		path(i, x, x + 1);
	}
	else {
		printf("1\n");
		path(x, j, x + 1);
	}
	return dp[i][j];
}


int main(void) {
	scanf("%d %d", &n, &m);
	map[0][0] = 1;
	map[0][1] = 1;
	map2[0][0] = n;
	map2[0][1] = n;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &map[i][0], &map[i][1]);
		map2[i][0] = map[i][0];
		map2[i][1] = map[i][1];
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", DP(0, 0, 1));
	path(0, 0, 1);
	return 0;
}