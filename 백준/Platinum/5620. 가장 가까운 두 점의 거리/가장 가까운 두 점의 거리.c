#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

typedef struct point {
	int x, y;
} point;

int n;
point ary[500010];

int cmp1(const void* num1, const void* num2) {
	return (*(point*)num1).x - (*(point*)num2).x;
}

int cmp2(const void* num1, const void* num2) {
	return (*(point*)num1).y - (*(point*)num2).y;
}

int dist(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int bf(int s, int e) {
	int res = INT_MAX;
	for (int i = s; i < e; ++i) {
		for (int j = i + 1; j <= e; ++j) {
			res = min(res, dist(ary[i], ary[j]));
		}
	}
	return res;
}

int findmin(int s, int e, int res) {
	int m = (s + e) / 2, d = 0;
	point ary2[500010];
	int idx = 0;
	int mind = ary[m].x;
	for (int i = s; i <= e; ++i) {
		d = ary[i].x - mind;
		if (d * d < res) {
			ary2[idx++] = ary[i];
		}
	}

	qsort(ary2, idx, sizeof(point), cmp2);

	mind = 0;
	for (int i = 0; i < idx - 1; ++i) {
		for (int j = i + 1; j < idx; ++j) {
			mind = ary2[i].y - ary2[j].y;
			if (mind * mind < res) {
				res = min(res, dist(ary2[i], ary2[j]));
				if (res == 0) return res;
			}
			else break;
		}
	}
	return res;
}

int solve(int s, int e) {
	if (e - s + 1 <= 3) return bf(s, e);
	
	int m = (s + e) / 2;

	int res1 = solve(s, m);
	int res2 = solve(m + 1, e);
	return findmin(s, e, min(res1, res2));
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &(ary[i].x), &(ary[i].y));
	qsort(ary, n, sizeof(point), cmp1);
	printf("%d\n", solve(0, n - 1));
	return 0;
}
