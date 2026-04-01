#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int data[20][20];

void DP(int n,int m) {
	if (n <= 0) return;
	DP(n - 1, m);
	int count = 0;
	for (int i = 1; i <= m; i++) {
		count += data[n-1][i];
		data[n][i] = count;
	}
}


int main() {
	int testcase,n,m;
	scanf("%d", &testcase);
	for (int i = 1; i < 16; i++) {
		data[0][i] = i;
	}
	for (int i1 = 0; i1 < testcase; i1++) {
		scanf("%d", &n);
		scanf("%d", &m);
		DP(n, m);
		printf("%d\n", data[n][m]);
	}

	return 0;
}