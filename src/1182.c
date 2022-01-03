#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int n, s;
int ary[50], res = 0;

void DP(int idx, int cnt) {
	if (idx >= n) return;
	
	if (cnt + ary[idx] == s) ++res;
	DP(idx + 1, cnt + ary[idx]);
	DP(idx + 1, cnt);
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; ++i) scanf("%d", &ary[i]);
	DP(0, 0);
	printf("%d\n", res);
	return 0;
}