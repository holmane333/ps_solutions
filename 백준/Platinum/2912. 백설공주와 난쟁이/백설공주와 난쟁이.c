#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct pair {
	long long a, b;
	int idx;
} pair;

long long n, c, m, ary[400020], visit[4000020], k, cnt, res[400020];
pair q[400020];

int cmp(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.a / k == b.a / k) return a.b - b.b;
	return a.a / k - b.a / k;
}

int main() {
	scanf("%lld %lld", &n, &c);
	for (int i = 1; i <= n; ++i) scanf("%lld", &ary[i]);
	scanf("%lld", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%lld %lld", &(q[i].a), &(q[i].b));
		q[i].idx = i;
	}
	k = (int)sqrt(n);
	qsort(q + 1, m, sizeof(pair), cmp);

	long long s = 0, e = 0;
	for (int i = 1; i <= m; ++i) {
		long long ns = q[i].a, ne = q[i].b;
		for (int j = s; j < ns; ++j) --visit[ary[j]];
		for (int j = ns; j < s; ++j) ++visit[ary[j]];
		for (int j = e + 1; j <= ne; ++j) ++visit[ary[j]];
		for (int j = ne + 1; j <= e; ++j) --visit[ary[j]];
		long long t = ne - ns + 1;
		for (int j = 1; j <= c; ++j) {
			if (visit[j] > (t >> 1)) {
				res[q[i].idx] = j;
				break;
			}
		}
		s = ns;
		e = ne;
	}
	for (int i = 1; i <= m; ++i) {
		if (!res[i]) printf("no\n");
		else printf("yes %lld\n", res[i]);
	}
	return 0;
}