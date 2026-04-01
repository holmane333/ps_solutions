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

long long n, m, ary[200020], visit[2000020], k, cnt, res[200020];
pair q[200020];

int cmp(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.a / k == b.a / k) return a.b - b.b;
	return a.a / k - b.a / k;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &ary[i]);
	for (int i = 1; i <= m; ++i) {
		scanf("%lld %lld", &(q[i].a), &(q[i].b));
		q[i].idx = i;
	}
	k = (int)sqrt(n);
	qsort(q + 1, m, sizeof(pair), cmp);
	
	long long s = q[1].a, e = q[1].b;
	for (int i = q[1].a; i <= q[1].b; ++i) ++visit[ary[i]], cnt += ary[i] * visit[ary[i]] * visit[ary[i]] - ary[i] * (visit[ary[i]] - 1) * (visit[ary[i]] - 1);
	res[q[1].idx] = cnt;
	for (int i = 2; i <= m; ++i) {
		long long ns = q[i].a, ne = q[i].b;
		for (int j = s; j < ns; ++j) --visit[ary[j]], cnt -= ary[j] * (visit[ary[j]] + 1) * (visit[ary[j]] + 1) - ary[j] * visit[ary[j]] * visit[ary[j]];
		for (int j = ns; j < s; ++j) ++visit[ary[j]], cnt += ary[j] * visit[ary[j]] * visit[ary[j]] - ary[j] * (visit[ary[j]] - 1) * (visit[ary[j]] - 1);
		for (int j = e + 1; j <= ne; ++j) ++visit[ary[j]], cnt += ary[j] * visit[ary[j]] * visit[ary[j]] - ary[j] * (visit[ary[j]] - 1) * (visit[ary[j]] - 1);
		for (int j = ne + 1; j <= e; ++j) --visit[ary[j]], cnt -= ary[j] * (visit[ary[j]] + 1) * (visit[ary[j]] + 1) - ary[j] * visit[ary[j]] * visit[ary[j]];
		res[q[i].idx] = cnt;
		s = ns;
		e = ne;
	}
	for (int i = 1; i <= m; ++i) {
		printf("%lld\n", res[i]);
	}
	return 0;
}