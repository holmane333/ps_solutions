#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, res = 0;

void bfs(int t, int cnt) {
	if (cnt == n) {
		if (!(t % 3)) res++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (!cnt && !i) continue;
		bfs(t + i, cnt + 1);
	}
}

int main() {
	scanf("%d", &n);
	bfs(0, 0);
	printf("%d\n", res);
	return 0;
}
