#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

typedef struct pair {
	int x, y;
} pair;

pair ary[100010] = {0, };
int check[100010] = {0, };

int cmp(const void* n1, const void* n2) {
	pair p1 = *(pair*)n1;
	pair p2 = *(pair*)n2;
	if (p1.x == p2.x) return p1.y - p2.y;
	return p1.x - p2.x;
}

void dfs(int n) {
	check[n] = 1;
	if (!check[ary[n].y]) dfs(ary[n].y);
}

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i].x);
		ary[i].y = i;
	}
	qsort(ary, n, sizeof(pair), cmp);
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n", n - cnt);

	return 0;
}
