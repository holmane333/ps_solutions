#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, sx, sy, rx, ry;
vector<string> a;
vector<vector<int>> v;
string s;
queue<pair<int, int>> q;
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }, dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1  };

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		v[i].resize(m);
		cin >> s;
		a.push_back(s);
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'K') {
				sx = i;
				sy = j;
			}
			if (a[i][j] == '*') {
				rx = i;
				ry = j;
			}
			v[i][j] = -1;
		}
	}
	q.push(make_pair(sx, sy));
	v[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
			if (a[cx][cy] == '#') continue;
			int t = 0;
			if (i >= 3) t = 1;
			if (v[cx][cy] == -1 || v[cx][cy] > v[x][y] + t) {
				v[cx][cy] = v[x][y] + t;
				q.push(make_pair(cx, cy));
			}
		}
	}

	cout << v[rx][ry] << "\n";
	return 0;
}
