#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[51][51], t, x, y, res, cnt, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
string s;
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> t;
	memset(a, -1, sizeof(a));
	while (t--) {
		cin >> s >> x >> y;
		if (s[9] == 'b') {
			a[x][y] = 15;
			q.push(make_pair(x, y));
		}
		else if (s[9] == 'd') {
			a[x][y] = -2;
		}
		else {
			a[x][y] = -3;
			++res;
		}
	}

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 0 || cx >= n || cy < 0 || cy >= m || a[cx][cy] == -1 || a[cx][cy] == -4) continue;
			if (a[cx][cy] == -3) {
				a[cx][cy] = -4;
				++cnt;
				continue;
			}
			if (a[cx][cy] == -2 || a[cx][cy] < a[x][y] - 1) {
				a[cx][cy] = a[x][y] - 1;
				if (a[cx][cy] > 0) {
					q.push(make_pair(cx, cy));
				}
			}
		}
	}

	if (res == cnt) cout << "success" << "\n";
	else cout << "failed" << "\n";
	return 0;
}