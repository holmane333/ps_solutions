#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct pair {
	int y;
	int x;
}pair;

int distance(pair w1, pair w2) {
	if (abs(w1.y - w2.y) + abs(w1.x - w2.x) <= 1000) return 1;
	else return 0;
}

int n, c, check[101];
pair map[101], res;

void dfs(pair w) {
	if (c) return;
	if (distance(w, res)) {
		c = 1;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (distance(w, map[i]) && !check[i]) {
			check[i] = 1;
			dfs(map[i]);
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		memset(check, 0, sizeof(check));
		memset(map, 0, sizeof(map));
		c = 0;
		scanf("%d", &n);
		pair home;
		scanf("%d %d", &home.y, &home.x);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &(map[i].y), &(map[i].x));
		}
		scanf("%d %d", &(res.y), &(res.x));

		dfs(home);
		if (c == 1) printf("happy\n");
		else printf("sad\n");
	}
	return 0;
}
