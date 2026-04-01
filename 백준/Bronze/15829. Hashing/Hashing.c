#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define mod 1234567891LL

int main(void) {
	int n;
	scanf("%d", &n);
	char ary[51];
	scanf("%s", ary);
	long long int res = 0LL, r = 1LL;
	for (int i = 0; i < n; i++) {
		res += ((long long int)(ary[i] - 'a' + 1) * r) % mod;
		res %= mod;
		r *= 31LL;
		r %= mod;
	}
	printf("%d\n", res);
	return 0;
}
