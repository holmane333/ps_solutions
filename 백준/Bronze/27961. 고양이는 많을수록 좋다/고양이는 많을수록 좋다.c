#pragma warning(disable:4996)
#include <stdio.h>
#define ll long long

int main(void) {
	ll a, b = 1LL;
	scanf("%lld", &a);
	int res = 0;
	while (a > b) {
		++res;
		b *= 2LL;
	}
	if (a == 0) printf("0\n");
	else printf("%lld\n", res + 1);
	
	return 0;
}
