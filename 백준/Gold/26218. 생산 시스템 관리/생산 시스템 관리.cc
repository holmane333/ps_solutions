#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[11][4];
ll dp[11][30010];
ll temp[11], res, resa[11][30010];

ll DP(int idx, int b) {
	if (idx >= n) return 1LL;
	if (dp[idx][b] != -1) return dp[idx][b];
	
	ll t, tt = temp[idx];
	dp[idx][b] = tt * DP(idx + 1, b);
	resa[idx][b] = tt;
	for (int i = 1; tt != 100LL; ++i) {
		if (b - (int)a[idx][2] * i < 0) break;
		tt = min(100LL, tt + a[idx][1]);
		t = tt * DP(idx + 1, b - (int)a[idx][2] * i);
		//cout << ' ' << idx << ' ' << b - (int)a[idx][2] * i << ' ' << tt << ' ' << '\n';
		//cout << t << ' ' << dp[idx][b] << '\n';
		if (dp[idx][b] < t) {
			dp[idx][b] = t;
			resa[idx][b] = tt;
		}
	}

	//cout << idx << ' ' << b << ' ' <<  dp[idx][b] << '\n';
	return dp[idx][b];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int b;
	cin >> n >> b;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		temp[i] = a[i][0];
		resa[i][b] = a[i][0];
	}

	res = 1LL;
	for (int i = 0; i < n; ++i) {
		res *= resa[i][b];
	}

	memset(dp, -1, sizeof(dp));
	cout << DP(0, b) << '\n';

	int t = 0;
	for (int i = 0; i < n; ++i) {
		cout << (resa[i][b - t] - a[i][0]) / a[i][1] + ((resa[i][b - t] - a[i][0]) % a[i][1] > 0LL) << ' ';
		t += (int)((resa[i][b - t] - a[i][0]) / a[i][1] + ((resa[i][b - t] - a[i][0]) % a[i][1] > 0LL)) * a[i][2];
		//cout << t << '\n';
	}
	cout << '\n';

	return 0;
}