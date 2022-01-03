#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

void add_zero2nine(int a, int b, long long int ary[], long long int len) {
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
	int n;
	long long int cnt[10] = {0LL, };
	scanf("%d", &n);
	
	if (n <= 9) {
		for (int i = 1; i <= n; i++) {
			cnt[i] += 1LL;
		}
	}
	else {
		long long int t = 1;
		while (t <= (long long int)n) {
			add_zero2nine(t, t * 10LL - 1LL < (long long int)n ? t * 10LL - 1LL : (long long int)n, cnt, 1LL);
			/*for (int i = 0; i <= 9; i++) {
				printf("%lld ", cnt[i]);
			}printf(": %lld ~ %lld", t, t * 10LL - 1LL); puts("");*/
			t *= 10;
		}
	}
	
	for (int i = 0; i <= 9; i++) {
		printf("%lld ", cnt[i]);
	}puts("");
	return 0;
}
