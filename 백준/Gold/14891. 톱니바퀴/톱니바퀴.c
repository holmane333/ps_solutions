#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

char str[9];
int tb[5][9], t, ix, d, n = 8, check[5];

void turn(int ix, int d) {
	int temp;
	switch (d)
	{
	case 1:
		temp = tb[ix][n - 1];
		for (int i = n - 1; i >= 0; i--) {
			tb[ix][i] = tb[ix][i - 1];
		}
		tb[ix][0] = temp;
		break;
	case -1:
		temp = tb[ix][0];
		for (int i = 0; i < n; i++) {
			tb[ix][i] = tb[ix][i + 1];
		}
		tb[ix][n - 1] = temp;
	}
}

void dfs(int ix, int d) {
	check[ix] = 1;
	if (ix < 3 && !check[ix + 1] && tb[ix][2] != tb[ix + 1][6]) {
		dfs(ix + 1, d == 1 ? -1 : 1);
	}
	if (ix > 0 && !check[ix - 1] && tb[ix][6] != tb[ix - 1][2]) {
		dfs(ix - 1, d == 1 ? -1 : 1);
	}

	turn(ix, d);
}

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%s", str);          //2는 오른쪽, 6은 왼쪽
		for (int j = 0; j < n; j++) {
			tb[i][j] = (int)str[j] - 48;
		}
	}
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &ix, &d);
		memset(check, 0, sizeof(check));
		dfs(ix - 1, d);
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		cnt += tb[i][0] * (1 << i);
	}

	printf("%d\n", cnt);

	return 0;
}
