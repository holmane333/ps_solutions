#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long

ll n, a, res, g, s, t;

ll gcd(ll n, ll a) {
	return !a ? n : gcd(a, n % a);
}

void egcd(ll n, ll a) {
	ll r1 = n, r2 = a, s1 = 1, s2 = 0, t1 = 0, t2 = 1, q, r;
	while (1) {
		q = r1 / r2;
		r = r1 - q * r2;
		s = s1 - q * s2;
		t = t1 - q * t2;
		
		if (!r){
			g = r2;
			s = s2;
			t = t2;
			break;
		}
		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}
}

int main() {
	scanf("%lld %lld", &n, &a);
	egcd(n, a);
	if (g == 1) res = (t + n) % n;
	else res = -1;
	printf("%lld %lld\n", n - a, res);
	return 0;
}