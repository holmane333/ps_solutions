#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long

ll a, b;
int v[1000010];

int main(void) {
	scanf("%lld %lld", &a, &b);
	
	ll res = b - a + 1, ii;
	for (ll i = 2; i * i <= b; ++i) {
		ii = i * i;
		ll temp = a / ii;
		if (temp * ii != a) ++temp;
		
		while (temp * ii <= b) {
			if (!v[temp * ii - a]) {
				--res;
				v[temp * ii - a] = 1;
			}
			++temp;
		}
	}
	
	printf("%lld\n", res);
	return 0;
}
