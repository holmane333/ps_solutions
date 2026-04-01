#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define ll long long
#define mod 1000000007

int main(void) {
	char a[100010];
	scanf("%s", a);
	ll t = 1, res = 0;
	int l = strlen(a);
	for (int i = 0; i < l; ++i) {
		if (a[i] == 'O') res += t;
		res %= mod;
		t *= 2;
		t %= mod;
	}
	
	printf("%lld\n", res);
	return 0;
}
