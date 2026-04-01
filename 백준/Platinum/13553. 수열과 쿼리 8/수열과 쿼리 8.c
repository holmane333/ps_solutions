#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct pair {
	long long a, b;
	int idx;
} pair;

long long n, m, k, ary[1000002], fen_tree[1000002], sqrtn, cnt, res[200020];
pair q[200020];

void update(int i, long long diff) {
	while (i <= 300001) {
		fen_tree[i] += diff;
		i += (i & -i);
	}
}

long long sum(int i) {
	long long res = 0;
	while (i > 0) {
		res += fen_tree[i];
		i -= (i & -i);
	}
	return res;
}

int cmp(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.a / sqrtn == b.a / sqrtn) return a.b - b.b;
	return a.a / sqrtn - b.a / sqrtn;
}

int main() {
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%lld", &ary[i]), ++ary[i];
	scanf("%lld", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%lld %lld", &(q[i].a), &(q[i].b));
		q[i].idx = i;
	}
	sqrtn = (long long)sqrt(n);
	qsort(q + 1, m, sizeof(pair), cmp);
	
	long long s = q[1].a, e = q[1].b;
	for (int i = q[1].a; i <= q[1].b; ++i) cnt += sum(ary[i] + k) - sum(max(2, ary[i] - k) - 1), update(ary[i], 1LL);
	
	
	res[q[1].idx] = cnt;
	for (int i = 2; i <= m; ++i) {
		long long ns = q[i].a, ne = q[i].b;
		for (int j = s; j < ns; ++j) update(ary[j], -1LL), cnt -= sum(ary[j] + k) - sum(max(2, ary[j] - k) - 1);
		for (int j = ns; j < s; ++j) cnt += sum(ary[j] + k) - sum(max(2, ary[j] - k) - 1), update(ary[j], 1LL);
		for (int j = e + 1; j <= ne; ++j) cnt += sum(ary[j] + k) - sum(max(2, ary[j] - k) - 1), update(ary[j], 1LL);
		for (int j = ne + 1; j <= e; ++j) update(ary[j], -1LL), cnt -= sum(ary[j] + k) - sum(max(2, ary[j] - k) - 1);
		res[q[i].idx] = cnt;
		s = ns;
		e = ne;
	}
	for (int i = 1; i <= m; ++i) {
		printf("%lld\n", res[i]);
	}
	return 0;
}

