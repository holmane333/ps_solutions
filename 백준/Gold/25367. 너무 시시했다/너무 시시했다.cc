#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc;
ll x, y, t, res;

// a + b = (a ^ b) + (a & b) * 2

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> tc;
	while (tc--) {
		cin >> x >> y;
		if (x < y || (x - y) % 2LL) {
			cout << 0 << '\n';
			continue;
		}
		x = (x - y) / 2LL;
		res = 1LL;
		for (int i = 0; i < 62; ++i) {
			t = (1LL << i);
			if ((y & t) && (x & t)) {
				res = 0LL;
				break;
			}
			if (y & t) {
				res *= 2LL;
			}

		}
		cout << res << '\n';
	}

	return 0;
}