#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, d;
ll **a, **dp;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> d;
	a = (ll**)malloc(sizeof(ll) * (n + 2));
	for (int i = 0; i <= n; ++i) {
		a[i] = (ll*)malloc(sizeof(ll) * (m + 2));
	}
	dp = (ll**)malloc(sizeof(ll) * (n + 2));
	for (int i = 0; i <= n; ++i) {
		dp[i] = (ll*)malloc(sizeof(ll) * (m + 2));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			dp[i][j] = -(ll)1e12;
			if (i == 1) dp[i][j] = 0LL;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = i + 1; k <= i + d; ++k) {
				if (k > n) break;
				for (int t = j - d; t <= j + d; ++t) {
					if (t <= 0) continue;
					if (t > m) break;
					if (k - i + abs(t - j) <= d)
						dp[k][t] = max(dp[k][t], dp[i][j] + a[i][j] * a[k][t]);
				}
			}
		}
	}
	ll res = (ll)-1e12;
	for (int i = 1; i <= m; ++i) {
		res = max(res, dp[n][i]);
	}
	cout << res << "\n";
	return 0;
}