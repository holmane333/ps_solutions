#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[2510], dp[2510], nows;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = n; i >= 1; --i) {
		nows = a[i];
		dp[i] = dp[i + 1];
		for (int j = i + 1; j <= n; ++j) {
			nows = a[j] - nows;
			if (nows < 0) break;
			if (!nows) dp[i] = max(dp[i], dp[j + 1] + 1);
		}
	}
	cout << n - dp[1] << '\n';
	return 0;
}