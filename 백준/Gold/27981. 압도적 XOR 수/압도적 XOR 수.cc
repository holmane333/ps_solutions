#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, t, res = 0LL;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	if (k == 1LL) {
		cout << n << "\n";
		return 0;
	}
	for (ll i = 1;; ++i) {
		//cout << res << "\n";
		t = (1LL << i) - 1LL;
		if (t >= n) {
			if (i < k) {
				if (t == n) ++res;
				break;
			}
			ll t2 = (1LL << (i - k)) - 1LL;
			res += ((n - (t - t2)) > 0 ? (n - (t - t2)) + 1 : 0);
			break;
		}
		else {
			if (i < k) ++res;
			else {
				res += 1LL << (i - k);
			}
		}
	}
	cout << res << "\n";
	return 0;
}
