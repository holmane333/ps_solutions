#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define ll long long

ll dx[5] = {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};

ll gcd(ll a, ll b){
	if (!b) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

ll dig(ll x) {
	if (x < 10) return x;
	ll res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return dig(res);
}

int main() {
	int tc;
	int v[20] = {0, };
	scanf("%d", &tc);
	for (int test = 0; test < tc; ++test) {
		memset(v, 0, sizeof(v));
		ll k, m, n = 1LL, cnt = 1, x = 0, y = 1, c = 0;
		v[1] = 1;
		scanf("%lld %lld", &k, &m);
		n = m;
		//printf(" %lld %lld\n", x, y);
		while (cnt < k) {
			ll now = dig(n);
			if (v[(int)now] && !c) {
				c = cnt - v[(int)now] + 1;
				c = lcm(c, 4);
				k -= ((k - cnt) / c) * c;
				continue;
			}
			ll cx = dx[cnt % 4], cy = dy[cnt % 4];
			x += cx * now;
			y += cy * now;
			v[(int)now] = ++cnt;
			n = now;
			n *= m;
			//printf(" %lld %lld %lld %lld %lld %lld\n", x, y, cnt, c, n, k);
		}
		
		printf("%lld %lld\n", x, y);
	}
	
	
	return 0;
}