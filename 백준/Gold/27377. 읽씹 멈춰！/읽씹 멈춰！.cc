#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc;
ll n, s, t, res;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> tc;
	while (tc--) {
		cin >> n >> s >> t;
		res = 0LL;
		while (n > 0) {
			if (n % 2) {
				--n;
				res += s;
			}
			else {
				if (n < (double)t / s * 2) res += n * s, n = 0;
				else res += t, n /= 2;
			}
		}

		cout << res << '\n';
	}

	return 0;
}