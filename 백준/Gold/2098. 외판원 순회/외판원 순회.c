#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, max, res = 1000000000;
int dp[20][100000];
int map[20][20];
int s = 0, k;

int travel(int t, int check) {
	if (check == max) {
		return map[t][s] == 0 ? 1000000000 : map[t][s];
	}

	if (dp[t][check]!= -1) return dp[t][check];

	int res2 = 1000000000, tra;
	for (int i = 0; i < n; i++) 
		if (!(check & (1 << i)) && map[t][i]) {
			tra = travel(i, check | 1 << i) + map[t][i];
			res2 = res2 < tra ? res2 : tra;
		}
	
	dp[t][check] = res2;
	return res2;
}

int main() {
	memset(dp, -1, sizeof(int) * 20 * 100000);
	scanf("%d", &n);
	max = (1 << n) - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	res = travel(0, 1);
	printf("%d\n", res);
	return 0;
}


