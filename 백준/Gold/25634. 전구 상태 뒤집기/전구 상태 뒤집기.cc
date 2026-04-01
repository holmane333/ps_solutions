#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[200010], b[200010], dp[200010][3], s[200010];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		s[i] = s[i - 1] + (b[i] ? a[i] : 0);
	}
	
	for (int i = 1; i <= n + 1; ++i) {
		dp[i][0] = max(dp[i - 1][0] + (b[i] ? 0 : a[i]), s[i - 1] + (b[i] ? 0 : a[i]));
		if (i == 1) dp[i][1] = dp[i][0];
		else dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + (b[i] ? a[i] : 0);
	}
	/*
	for (int i = 1; i <= n + 1; ++i) {
		cout << dp[i][0] << ' ';
	}cout << '\n';
	for (int i = 1; i <= n + 1; ++i) {
		cout << dp[i][1] << ' ';
	}cout << '\n';*/

	cout << dp[n + 1][1] << "\n";

	return 0;
}