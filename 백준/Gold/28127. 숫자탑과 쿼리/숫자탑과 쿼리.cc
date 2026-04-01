#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q;
ll a, d, x;

ll rsum(ll mid) {
	return mid * (2LL * a + (mid - 1) * d) / 2LL;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> q;

	while (q--) {
		cin >> a >> d >> x;
		ll left = 1LL, right = 1000001LL, res = 1000001LL;
		while (left <= right) {
			ll mid = (left + right) / 2LL;
			ll s = rsum(mid);
			//cout << mid << " " << s << " " << "\n";
			if (s >= x) {
				res = mid;
				right = mid - 1LL;
			}
			else left = mid + 1LL;
		}

		x -= rsum(res - 1LL);
		cout << res << " " << x << "\n";
	}

	return 0;
}
