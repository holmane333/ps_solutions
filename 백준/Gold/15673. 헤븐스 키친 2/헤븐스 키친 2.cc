#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[100010][3][3] = {0LL, }, a[100010] = {0LL, }, res = (ll)-1e9;


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		dp[i][0][0] = max(a[i], dp[i - 1][0][0] + a[i]);
		dp[i][0][1] = min(a[i], dp[i - 1][0][1] + a[i]);
	}

	for (int i = 2; i <= n; ++i) {
		dp[i][0][0] = max(dp[i - 1][0][0], dp[i][0][0]);
		dp[i][0][1] = min(dp[i - 1][0][1], dp[i][0][1]);
	}

	for (int i = n; i >= 1; --i) {
		dp[i][1][0] = max(a[i], dp[i + 1][1][0] + a[i]);
		dp[i][1][1] = min(a[i], dp[i + 1][1][1] + a[i]);
	}

	for (int i = n - 1; i >= 1; --i) {
		dp[i][1][0] = max(dp[i + 1][1][0], dp[i][1][0]);
		dp[i][1][1] = min(dp[i + 1][1][1], dp[i][1][1]);
	}

	for (int i = 1; i < n; ++i) {
		res = max(res, max(dp[i][0][0] * dp[i + 1][1][0], dp[i][0][1] * dp[i + 1][1][1]));
	}
	cout << res << '\n';
	return 0;
}