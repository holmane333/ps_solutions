#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
string s1, s2;
int dp[5010][5010];

int DP(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	int t = 0;
	if (x - 1 >= 0 && (s1[x - 1] == s2[y])) t = 1;
	dp[x][y] = max(dp[x][y], DP(x - 1, y + 1) + t);
	if (x + 1 < n && s1[x + 1] == s2[y]) t = 1;
	else t = 0;
	dp[x][y] = max(dp[x][y], DP(x + 1, y + 1) + t);

	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	cin >> s1;
	cin >> s2;
	memset(dp, -1, sizeof(dp));

	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, DP(i, 0));
	}
	cout << res << "\n";
	return 0;
}
