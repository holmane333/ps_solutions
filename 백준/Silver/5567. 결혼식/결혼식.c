#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int arr[501][501], res[501], check[501];
int n;

void dfs(int x, int cnt) {
	if (cnt == 2) return;
	for (int i = 1; i <= n; i++) {
		if (arr[x][i] && !check[i]) {
			check[i] = 1;
			res[i] = 1;
			dfs(i, cnt + 1);
			check[i] = 0;
		}
	}

}

int main() {
	int m, a1, a2;
	scanf("%d\n%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a1, &a2);
		arr[a1][a2] = 1;
		arr[a2][a1] = 1;
	}
	dfs(1, 0);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (res[i]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}