//28259
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, h, k, v[510] = { 0, }, temp;
ll res;
ll dp[510][70];

ll DP(int x, int y) {
	if (y >= h) return 0LL;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = (ll)3e18;

	for (int i = 0; i < n; ++i) {
		int t = x - i, cnt = 0;
		if (t < 0) t += n;
		cnt += (v[t] ? 0 : 1) + (v[i] ? 0 : 1);
		dp[x][y] = min(dp[x][y], DP(t, y + 1) + DP(i, y + 1) + (ll)cnt);
	}

	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> h >> k;
	for (int i = 0; i < k; ++i) {
		cin >> temp;
		v[temp] = 1;
	}
	res = (ll)3e18;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i) {
		res = min(res, DP(i, 0) + (v[i] ? 0LL : 1LL));
	}
	cout << res << "\n";
	return 0;
}