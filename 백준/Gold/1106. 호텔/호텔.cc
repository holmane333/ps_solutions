#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, n, a[30][2], dp[30][2010];

int DP(int i, int nowc) {
	if (i >= n) {
		if (nowc >= c) return 0;
		else return (int)1e9;
	}
	if (dp[i][nowc] != -1) return dp[i][nowc];
	
	dp[i][nowc] = (int)1e9;
	
	for (int j = 0;; ++j) {
		dp[i][nowc] = min(dp[i][nowc], DP(i + 1, nowc + j * a[i][1]) + j * a[i][0]);
		if (nowc + j * a[i][1] > c) break;
	}

	//cout << i << " " << nowc << " " << dp[i][nowc] << "\n";
	return dp[i][nowc];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> c >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}

	memset(dp, -1, sizeof(dp));
	cout << DP(0, 0) << "\n";

	return 0;
}