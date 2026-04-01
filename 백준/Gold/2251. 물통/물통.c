#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int a, b, c;
int ary[201][201][201];
int res[201];

typedef struct pair {
	int a;
	int b;
	int c;
}pair;

void dfs(pair w) {
	ary[w.a][w.b][w.c] = 1;
	if (w.a == 0) res[w.c] = 1;

	
	if (w.a != 0) {
		pair new1 = { b - (w.a + w.b) >= 0 ? 0 : (w.a + w.b) - b, b - (w.a + w.b) >= 0 ? w.a + w.b : b ,w.c };
		pair new2 = { c - (w.a + w.c) >= 0 ? 0 : (w.a + w.c) - c, w.b, c - (w.a + w.c) >= 0 ? w.a + w.c : c };
		if (!ary[new1.a][new1.b][new1.c]) dfs(new1);
		if (!ary[new2.a][new2.b][new2.c]) dfs(new2);
	}
	if (w.b != 0) {
		pair new1 = { a - (w.a + w.b) >= 0 ? w.a + w.b : a, a - (w.a + w.b) >= 0 ? 0 : (w.a + w.b) - a, w.c };
		pair new2 = { w.a, c - (w.b + w.c) >= 0 ? 0 : (w.b + w.c) - c, c - (w.b + w.c) >= 0 ? w.b + w.c : c };
		if (!ary[new1.a][new1.b][new1.c]) dfs(new1);
		if (!ary[new2.a][new2.b][new2.c]) dfs(new2);
	}
	if (w.c != 0) {
		pair new1 = { a - (w.a + w.c) >= 0 ? w.a + w.c : a, w.b, a - (w.a + w.c) >= 0 ? 0 : (w.a + w.c) - a };
		pair new2 = { w.a, b - (w.b + w.c) >= 0 ? w.b + w.c : b, b - (w.b + w.c) >= 0 ? 0 : (w.b + w.c) - b };
		if (!ary[new1.a][new1.b][new1.c]) dfs(new1);
		if (!ary[new2.a][new2.b][new2.c]) dfs(new2);
	}
}

int main() {
	scanf("%d %d %d", &a, &b, &c);
	pair newi = { 0,0,c };
	dfs(newi);

	for (int i = 0; i <= c; i++) {
		if (res[i]) printf("%d ", i);
	}
	/*
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				printf("%d ", ary[i][j][k]);
			}puts("");
		}puts("");
	}*/
	return 0;
}
