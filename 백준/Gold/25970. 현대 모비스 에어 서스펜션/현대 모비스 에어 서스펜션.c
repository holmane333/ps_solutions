#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define ll long long

void printBit(int n) { 
    if(n>1) printBit(n>>1); 
    printf("%d", n&1); 
} 

int main(void) {
	char s[260];
	int b, n, llen[510], hlen[510], slen, res;
	ll l[510] = {0LL, }, h[510] = {0LL, };
	scanf("%d", &b);
	for (int i = 0; i < b; ++i) {
		scanf("%s", s);
		llen[i] = strlen(s);
		for (int j = llen[i] - 1; j >= 0; --j) {
			l[i] = (l[i] << 1) | (int)(s[j] - '0');
		}
	}
	for (int i = 0; i < b; ++i) {
		scanf("%s", s);
		hlen[i] = strlen(s);
		for (int j = hlen[i] - 1; j >= 0; --j) {
			h[i] = (h[i] << 1) | (int)(s[j] - '0');
		}
	}
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		ll bit = 0LL, m = (1 << 52) - 1;
		slen = strlen(s);
		res = 0;
		for (int j = slen - 1; j >= 0; --j) {
			bit = ((bit << 1LL) | (int)(s[j] - '0')) & m;
			for (int k = 0; k < b; ++k) {
				if ((((1LL << llen[k]) - 1LL) & bit) == l[k] && llen[k] <= slen - j) ++res;
				if ((((1LL << hlen[k]) - 1LL) & bit) == h[k] && hlen[k] <= slen - j) --res;
			}
		}
		if (res > 0) printf("HIGH %d\n", res);
		else if (res < 0) printf("LOW %d\n", -res);
		else printf("GOOD\n");
	}
	
	return 0;
}
