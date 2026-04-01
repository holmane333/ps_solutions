#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc, C, D, d, t1[110], t2[110], t1len, t2len, temp, dp[110][110][3][3];

int DP(int a, int b, int ta, int tb) {
	if (a == t1len && b == t2len) return 0;
	if (dp[a][b][ta][tb] != -1) return dp[a][b][ta][tb];
	dp[a][b][ta][tb] = (int)1e9;
	if (a < t1len && b < t2len) {
		if (t1[a] == t2[b]) {
			dp[a][b][ta][tb] = C + DP(a + 1, b + 1, 0, 0);
		}
		else {
			dp[a][b][ta][tb] = C * 2 + DP(a + 1, b + 1, 0, 0);
		}
	}
	if (b < t2len) {
		if (ta) {
			dp[a][b][ta][tb] = min(dp[a][b][ta][tb], C + d + DP(a, b + 1, 1, 0));
		}
		else {
			dp[a][b][ta][tb] = min(dp[a][b][ta][tb], C + D + d + DP(a, b + 1, 1, 0));
		}
	}
	if (a < t1len) {
		if (tb) {
			dp[a][b][ta][tb] = min(dp[a][b][ta][tb], C + d + DP(a + 1, b, 0, 1));
		}
		else {
			dp[a][b][ta][tb] = min(dp[a][b][ta][tb], C + D + d + DP(a + 1, b, 0, 1));
		}
	}

	return dp[a][b][ta][tb];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> tc;
	while (tc--) {
		cin >> C >> D >> d;
		t1len = t2len = 0;
		while (1) {
			cin >> temp;
			if (!temp) break;
			t1[t1len++] = temp;
		}
		while (1) {
			cin >> temp;
			if (!temp) break;
			t2[t2len++] = temp;
		}
		memset(dp, -1, sizeof(dp));
		cout << DP(0, 0, 0, 0) << "\n";
	}
	return 0;
}