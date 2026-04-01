#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)

int n, max;
double res;
double dp[20][100000];
double map[20][20], ary[20][2];
int s = 0;

double travel(int t, int check) {
	if (check == max) {
		return map[t][s] == 0.0 ? 1000000000.0 : map[t][s];
	}

	if (dp[t][check]!= -1.0) return dp[t][check];

	double res2 = 1000000000.0, tra;
	for (int i = 0; i < n; i++) 
		if (!(check & (1 << i)) && map[t][i]) {
			tra = travel(i, check | 1 << i) + map[t][i];
			res2 = res2 < tra ? res2 : tra;
		}
	
	dp[t][check] = res2;
	return res2;
}

int main() {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 100000; ++j) {
			dp[i][j] = -1.0;
		}
	}
	scanf("%d", &n);
	max = (1 << n) - 1;
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf", &ary[i][0], &ary[i][1]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = sqrt((ary[i][0] - ary[j][0]) * (ary[i][0] - ary[j][0]) + (ary[i][1] - ary[j][1]) * (ary[i][1] - ary[j][1]));
			map[j][i] = sqrt((ary[i][0] - ary[j][0]) * (ary[i][0] - ary[j][0]) + (ary[i][1] - ary[j][1]) * (ary[i][1] - ary[j][1]));
		}
	}
	res = travel(0, 1);
	printf("%.20lf\n", res);
	return 0;
}


