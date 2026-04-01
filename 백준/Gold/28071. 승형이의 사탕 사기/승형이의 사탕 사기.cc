#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k, a[310];
int dp[310][310];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i <= 300; ++i)
		for (int j = 0; j <= 300; ++j)
			dp[i][j] = 0;
	for (int i = 0; i < n; ++i) {
		dp[1][a[i] % k] = max(dp[1][a[i] % k], a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int t = 0; t < n; ++t) {
				if (dp[i][(j - a[t] + k * 300) % k]) dp[i + 1][j] = max(dp[i + 1][j], dp[i][(j - a[t] + k * 300) % k] + a[t]);
				//cout << i + 1 << " " << j << " " << (j - a[t] + k * 300) % k << " " << dp[i + 1][j] << "\n";
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= m; ++i) {
		res = max(res, dp[i][0]);
	}
	cout << res << "\n";
	return 0;
}
