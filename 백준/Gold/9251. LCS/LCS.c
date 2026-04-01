#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int dp[1010][1010];
char str1[1010], str2[1010];

void DP(int x,int y) {
	dp[x][y] = max(max(dp[x - 1][y], dp[x][y - 1]), dp[x - 1][y - 1] + (str1[x] == str2[y]));
	if (x == strlen(str1) && y == strlen(str2)) return;
	if (x >= strlen(str1)) DP(1, y + 1);
	else DP(x + 1, y);
}

int main() {
	scanf("%s", str1 + 1);
	scanf("%s", str2 + 1);
	str1[0] = 'a';
	str2[0] = 'a';
	DP(1, 1);
	
	printf("%d\n", dp[strlen(str1) - 1][strlen(str2) - 1]);
	return 0;
}
