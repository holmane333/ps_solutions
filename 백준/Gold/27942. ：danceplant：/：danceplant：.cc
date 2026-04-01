#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, xx1, yy1, xx2, yy2, t, p, res, dx1[4] = { -1, 0, 0, 0 }, dx2[4] = { 0, 1, 0, 0 }, dy1[4] = { 0,0,-1,0 }, dy2[4] = { 0,0,0,1 };
vector<vector<int>> m, s1, s2;
string resp, dp[4] = { "U", "D", "L", "R" };

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	xx1 = n / 2, yy1 = n / 2, xx2 = n / 2 + 1, yy2 = n / 2 + 1;
	m.resize(n + 2);
	s1.resize(n + 2);
	s2.resize(n + 2);
	for (int i = 0; i <= n + 1; ++i) m[i].resize(n + 2), s1[i].resize(n + 2), s2[i].resize(n + 2);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> m[i][j];
			s1[i][j] = m[i][j] + s1[i - 1][j];
			s2[i][j] = m[i][j] + s2[i][j - 1];
		}
	}
	
	while (true) {
		t = 0, p = -1;
		if (xx1 > 1 && t < s2[xx1 - 1][yy2] - s2[xx1 - 1][yy1 - 1]) {
			t = s2[xx1 - 1][yy2] - s2[xx1 - 1][yy1 - 1];
			p = 0;
		}
		if (xx2 < n && t < s2[xx2 + 1][yy2] - s2[xx2 + 1][yy1 - 1]) {
			t = s2[xx2 + 1][yy2] - s2[xx2 + 1][yy1 - 1];
			p = 1;
		}
		if (yy1 > 1 && t < s1[xx2][yy1 - 1] - s1[xx1 - 1][yy1 - 1]) {
			t = s1[xx2][yy1 - 1] - s1[xx1 - 1][yy1 - 1];
			p = 2;
		}
		if (yy2 < n && t < s1[xx2][yy2 + 1] - s1[xx1 - 1][yy2 + 1]) {
			t = s1[xx2][yy2 + 1] - s1[xx1 - 1][yy2 + 1];
			p = 3;
		}
		
		if (t <= 0) break;
		xx1 += dx1[p];
		yy1 += dy1[p];
		xx2 += dx2[p];
		yy2 += dy2[p];
		res += t;
		resp += dp[p];
	}
	
	cout << res << "\n" << resp << "\n";
	return 0;
}
