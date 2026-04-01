#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, l, dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
ll res, dp[210][210][110];
char s[110], a[210][210];

ll DP(int x, int y, int cnt) {
	if (dp[x][y][cnt] != -1) return dp[x][y][cnt];
	if (cnt == l - 1) return 1LL;
	dp[x][y][cnt] = 0LL;
	for (int i = 0; i < 8; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
		if (a[cx][cy] != s[cnt + 1]) continue;
		dp[x][y][cnt] += DP(cx, cy, cnt + 1);
	}
	return dp[x][y][cnt];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> l;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> s;

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == s[0]) res += DP(i, j, 0);
		}
	}

	cout << res << '\n';
	return 0;
}