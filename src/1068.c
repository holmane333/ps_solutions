#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct pair {
	int n;
	int t;  //0이면 리프, 1이면 아님
}pair;

pair tree[60];
int n, data;

void dfs(int k) {
	tree[k].t = -1;
	for (int i = 0; i < n; i++) {
		if (tree[i].n == k) {
			dfs(i);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &(tree[i].n));
	}
	scanf("%d", &data);
	dfs(data);
	for (int i = 0; i < n; i++) {
		if ((tree[i].n != -1) && tree[i].t != -1) tree[tree[i].n].t = 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!(tree[i].t)) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
