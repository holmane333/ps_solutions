#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

long long int gcd(long long int a, long long int b) {
	if (b == 0LL) return a;
	return gcd(b, a % b);
}

int main() {
	long long int n, m, temp;
	scanf("%lld %lld", &n, &m);
	if (n < m) swap(n, m, temp);
	printf("%lld\n", n + m - gcd(n, m));
	return 0;
}
