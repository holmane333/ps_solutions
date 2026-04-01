#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string w1, w2, w3;
int dp[10010][4];
int n, x, y;

int DP(int idx, int t) {
	if (idx >= n) return 1;
	if (dp[idx][t] != -1) return dp[idx][t];
	dp[idx][t] = 0;
	if (idx - t < n - 2 && w2[idx] == w1[idx - t]) dp[idx][t] |= DP(idx + 1, t);
	if (t < 2 && w2[idx] == w3[t]) dp[idx][t] |= DP(idx + 1, t + 1);
	
	return dp[idx][t];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> w1 >> w2 >> x >> y;
	w3.push_back(w1[x]); w3.push_back(w1[y]);

	memset(dp, -1, sizeof(dp));

	w1.erase(w1.begin() + y);
	w1.erase(w1.begin() + x);
	
	if (DP(0, 0)) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}