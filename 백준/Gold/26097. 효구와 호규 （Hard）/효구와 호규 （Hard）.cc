#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[1010][1010], prev0[4], prev1[4], s0[1000010][2], idx0, s1[1000010][2], idx1, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, cnt0, cnt1, c, firstx1, firsty1, firstx2, firsty2;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1) ++cnt1;
			else ++cnt0;
		}
	}

	if ((cnt1 & 1) || (cnt0 & 1)) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (c) break;
		for (int j = 1; j <= m; ++j) {
			if (c) break;
			prev0[0] = prev1[0] = 0;
			for (int k = 0; k < 4; ++k) {
				int cx = i + dx[k];
				int cy = j + dy[k];
				if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
				if (a[i][j] == a[cx][cy]) {
					firstx1 = i;
					firsty1 = j;
					firstx2 = cx;
					firsty2 = cy;
					c = 1;
					break;
				}
			}
		}
	}

	if (!c) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if ((i == firstx1 && j == firsty1) || (i == firstx2 && j == firsty2)) continue;
			if (a[i][j]) {
				s1[idx1][0] = i;
				s1[idx1++][1] = j;
			}
			else {
				s0[idx0][0] = i;
				s0[idx0++][1] = j;
			}
		}
	}
	cout << 1 << '\n';
	cout << firstx1 << ' ' << firsty1 << ' ' << firstx2 << ' ' << firsty2 << '\n';
	for (int i = 0; i < idx0; i += 2) {
		cout << s0[i][0] << ' ' << s0[i][1] << ' ' << s0[i + 1][0] << ' ' << s0[i + 1][1] << '\n';
	}
	for (int i = 0; i < idx1; i += 2) {
		cout << s1[i][0] << ' ' << s1[i][1] << ' ' << s1[i + 1][0] << ' ' << s1[i + 1][1] << '\n';
	}
	return 0;
}