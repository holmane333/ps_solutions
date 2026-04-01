#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353;

int n, t;
ll dp[2010][2010];
vector<ll> a;
vector<vector<int>> e;

ll DP(int x, int l) {
	//cout << x << " " << l << "\n";
	if (e[x].empty()) return (l == 0 ? 1 : 0);
	if (dp[x][l] != -1) return dp[x][l];

	dp[x][l] = 0;
	if (l == 0) {
		for (int i = 0; i < e[x].size(); ++i) {
			for (int j = 0; j < a[x]; ++j) {
				dp[x][l] = (dp[x][l] + DP(e[x][i], j)) % MOD;
			}
		}
	}
	else {
		for (int i = 0; i < e[x].size(); ++i) {
			dp[x][l] = (dp[x][l] + DP(e[x][i], l - 1)) % MOD;
		}
	}
	return dp[x][l];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	e.resize(n + 1);
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		e[t].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	memset(dp, -1, sizeof(dp));
	ll r = DP(0, 1) % MOD;
	cout << r << "\n";
	return 0;
}
