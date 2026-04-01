#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define ll long long

ll add_zero2nine(ll a, ll b, ll ary[], ll len) {
	while(a % 10 != 0 && a < b) {
		int t = a;
		while (t != 0) {
			ary[t % 10] += len;
			t /= 10;
		}
		a++;
	}
	//printf("%d %d\n", a, b);
	if (a == b) {
		while (a != 0) {
			ary[a % 10] += len;
			a /= 10;
		}
		return;
	}
	while (b % 10 != 9 && a < b) {
		int t = b;
		while (t != 0) {
			ary[t % 10] += len;
			t /= 10;
		}
		b--;
	}
	//printf("%d %d\n", a, b);
	if (a == b) {
		while (a != 0) {
			ary[a % 10] += len;
			a /= 10;
		}
		return;
	}
	for (int i = 0; i <= 9; i++) {
		ary[i] += len * (b - a + 1) / 10;
	}
	add_zero2nine(a / 10, b / 10, ary, len * 10LL);
}

int main(void) {
	ll n, m;
	ll cnt[10] = {0LL, }, res1 = 0, res2 = 0;
	scanf("%lld %lld", &n, &m);
	
	n -= 1;
	n = max(n, 0);
	ll t = 1;
	while (t <= n) {
		add_zero2nine(t, t * 10LL - 1LL < n ? t * 10LL - 1LL : n, cnt, 1LL);
		/*for (int i = 0; i <= 9; i++) {
			printf("%lld ", cnt[i]);
		}printf(": %lld ~ %lld", t, t * 10LL - 1LL); puts("");*/
		t *= 10;
	}
	for (int i = 1; i <= 9; ++i) {
		res1 += cnt[i] * i;
		cnt[i] = 0LL;
	}
	
	t = 1;
	while (t <= m) {
		add_zero2nine(t, t * 10LL - 1LL < m ? t * 10LL - 1LL : m, cnt, 1LL);
		/*for (int i = 0; i <= 9; i++) {
			printf("%lld ", cnt[i]);
		}printf(": %lld ~ %lld", t, t * 10LL - 1LL); puts("");*/
		t *= 10;
	}
	for (int i = 1; i <= 9; ++i) {
		res2 += cnt[i] * i;
		cnt[i] = 0LL;
	}
	printf("%lld\n", res2 - res1);
	return 0;
}
