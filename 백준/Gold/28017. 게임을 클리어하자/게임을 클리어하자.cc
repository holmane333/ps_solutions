#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, t[510][510], dp[510][510];

int DP(int a, int b) {
	if (a >= n) return 0;
	if (dp[a][b] != -1) return dp[a][b];

	dp[a][b] = (int)1e9;
	for (int i = 0; i < m; ++i) {
		if (i == b) continue;
		dp[a][b] = min(dp[a][b], DP(a + 1, i) + t[a][i]);
	}
	return dp[a][b];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> t[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << DP(0, m + 1) << "\n";
	return 0;
}
