#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int n, k;
vector<pair<int, int>> a;
ll dp[3010][3010];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	a.resize(n + 2);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	
	for (int i = a[0].first; i <= a[0].second; ++i) dp[0][i] = 1LL;
	for (int i = 1; i <= 3000; ++i) dp[0][i] += dp[0][i - 1];

	for (int i = 1; i < n; ++i) {
		for (int j = a[i].first; j <= a[i].second; ++j) {
			dp[i][j] = (dp[i - 1][min(3000, j + k)] - dp[i - 1][max(0, j - k - 1)]) % MOD;
			while (dp[i][j] < 0) dp[i][j] = (dp[i][j] + MOD) % MOD;
			//cout << dp[i][j] << " " << "\n";
		}
		for (int j = 1; j <= 3000; ++j) dp[i][j] = (dp[i][j] + dp[i][j - 1] + MOD) % MOD;
	}

	ll res = (dp[n - 1][a[n - 1].second] - dp[n - 1][a[n - 1].first - 1]) % MOD;
	while (res < 0) res = (res + MOD) % MOD;
	cout << res << "\n";
	
	return 0;
}
