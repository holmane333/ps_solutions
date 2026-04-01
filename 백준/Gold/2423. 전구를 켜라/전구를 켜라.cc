#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, v[1510][1510], dx[4] = { 1, 1, 0, 0 }, dy[4] = {1, 0, 1, 0}, tx[4] = {1, 1, -1, -1}, ty[4] = {1, -1, 1, -1};
char a[1510][1510], temp[1510], dc[4] = { '\\', '/', '/', '\\' };
queue<pair<pair<int, int>, int>> q;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	n <<= 1;
	m <<= 1;
	for (int i = 2; i <= n; i += 2) {
		cin >> temp + 1;
		for (int j = 2; j <= m; j += 2) {
			a[i][j] = temp[j / 2];
		}
	}
	
	for (int i = 0; i <= 1500; ++i)
		for (int j = 0; j <= 1500; ++j) v[i][j] = (int)1e9;
	q.push(make_pair(make_pair(1, 1), 0));
	v[1][1] = 0;
	while (!q.empty()) {
		pair<pair<int, int>, int> p = q.front(); q.pop();
		//cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
		for (int i = 0; i < 4; ++i) {
			int cx = p.first.first + tx[i];
			int cy = p.first.second + ty[i];
			int cc = p.second;
			if (cx < 1 || cx > n + 1 || cy < 1 || cy > m + 1) continue;
			if (a[cx][cy] != dc[i]) ++cc;
			cx += tx[i];
			cy += ty[i];
			if (v[cx][cy] > cc) {
				v[cx][cy] = cc;
				q.push(make_pair(make_pair(cx, cy), cc));
			}
		}
	}

	if (v[n + 1][m + 1] == (int)1e9) cout << "NO SOLUTION\n";
	else cout << v[n + 1][m + 1] << '\n';
	return 0;
}