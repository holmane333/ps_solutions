#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
int s[5][5];
int step[100001];
int len = 1;
const int INF = 987654321;
 
int dp_table[100001][5][5];
 
int dp(int cur, int l, int r) {
	if (cur == len - 1) return 0;
	if ((l !=0 && r != 0) && l == r) return INF;
 
	if (dp_table[cur][l][r] != -1) return dp_table[cur][l][r];
 
	return dp_table[cur][l][r] = min(dp(cur + 1, step[cur + 1], r) + s[l][step[cur + 1]], dp(cur + 1, l, step[cur + 1]) + s[r][step[cur + 1]]);
}

int main() {
	scanf("%d", &step[len++]);
 
	while (step[len - 1] != 0) 
		scanf("%d", &step[len++]);
	
	memset(dp_table, -1, sizeof(dp_table));

	for (int i = 0; i <= 4; ++i) 
		s[i][i] = 1;
	for (int i = 1; i <= 4; ++i) {
		s[0][i] = 2;
	}
	s[1][2] = s[1][4] = s[2][1] = s[2][3] = s[3][2] = s[3][4] = s[4][3] = s[4][1] = 3;
	s[1][3] = s[2][4] = s[3][1] = s[4][2] = 4;
 
	printf("%d", dp(0, 0, 0));
 
	return 0;
}