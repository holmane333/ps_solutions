#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int dp[1000010];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	
	dp[0] = 0;
	for (int i = 0; i <= n; ++i) dp[i] = i;
	for (int i = 0; i < n; ++i) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i + i / 2 <= n) dp[i + i / 2] = min(dp[i + i / 2], dp[i] + 1);
	}
	cout << (dp[n] <= k ? "minigimbob" : "water") << "\n";
	return 0;
}
