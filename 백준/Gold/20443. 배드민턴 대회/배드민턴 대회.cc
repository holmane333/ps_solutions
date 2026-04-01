#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll n;
	cin >> n;
	dp[0] = dp[1] = 0LL;
	dp[2] = 1LL;
	for (int i = 3; i <= 100; ++i) dp[i] = ((dp[i - 1] + dp[i - 2]) * (i - 1)) % 1000000007;
	
	ll res = dp[n - n % 4];
	if (n % 4 == 3) res = res * n * (n - 1) * (n - 2) / 6LL % 1000000007;
	else if (n % 4 == 2) res = res * n * (n - 1) / 2LL % 1000000007;
	else if (n % 4 == 1) res = res * n % 1000000007;

	cout << res % 1000000007;

	return 0;
}