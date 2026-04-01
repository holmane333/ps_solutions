#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, b, c, d, t, res = (ll)2e18;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> a >> b >> c >> d;
	if (b * c > a * d) {
		t = b; b = d; d = t; t = a; a = c; c = t;
	}

	for (int i = 0; i < a; ++i) {
		t = max((n - c * i) / a + ((n - c * i) % a > 0 ? 1 : 0), 0LL);
		//cout << res << " " << t << " " << d * i << "\n";
		res = min(res, b * t + d * i);
	}

	cout << res << "\n";
	return 0;
}
