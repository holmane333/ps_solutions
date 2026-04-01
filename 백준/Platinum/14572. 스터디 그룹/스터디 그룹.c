#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct pair {
	int len, d;
	int algo[40];
} pair;

int n, k, d;
pair p1[100020];

int cmp(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	return a.d > b.d;
}

int main() {
	scanf("%d %d %d", &n, &k, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &(p1[i].len), &(p1[i].d));
		for (int j = 1; j <= p1[i].len; ++j) {
			scanf("%d", &(p1[i].algo[j]));
		}
	}
	qsort(p1 + 1, n, sizeof(pair), cmp);
	
	int prev = 1, post = 1, res = 0, algo[40] = {0, };
	while(post != n + 1) {
		while (p1[post].d - p1[prev].d > d) {
			for (int i = 1; i <= p1[prev].len; ++i) --algo[p1[prev].algo[i]];
			++prev;
		}
		for (int i = 1; i <= p1[post].len; ++i) ++algo[p1[post].algo[i]];
		int cnt = 0;
		for (int i = 1; i <= k; ++i) if (algo[i] > 0 && algo[i] < post - prev + 1) ++cnt;
		res = max(res, cnt * (post - prev + 1));
		//printf("%d %d %d %d\n", post, prev, cnt, cnt * (post - prev + 1));
		++post;
		//for (int i = 0; i <= k; ++i) printf("%d ", algo[i]); puts("");
	}
	printf("%d\n", res);
	
	return 0;
}