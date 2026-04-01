#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc, n, m, cnt, keyv = 1;
string s;
int ary[300][300], v[300][300], r[100000], b[100000], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, res[10];
char ac[10] = {'A', 'D', 'J', 'K', 'S', 'W'};

void dfs1(int x, int y, int k) {
	v[x][y] = k;
	//cout << x << " " << y << "\n";
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx < 1 || cx > n || cy < 1 || cy > m) {
			b[k] = 1;
			continue;
		}
		if (v[cx][cy] || ary[cx][cy]) continue;
		dfs1(cx, cy, k);
	}
}

void dfs2(int x, int y, int k) {
	v[x][y] = k;
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
		if (ary[cx][cy] == 0) {
			if (!r[v[cx][cy]] && !b[v[cx][cy]]) {
				r[v[cx][cy]] = 1;
				++cnt;
			}
			continue;
		}
		if (v[cx][cy]) continue;
		dfs2(cx, cy, k);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int tc = 1;
	while (1) {
		memset(v, 0, sizeof(v));
		memset(res, 0, sizeof(res));
		memset(b, 0, sizeof(b));
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; ++i) {
			cin >> s;
			for (int j = 0; j < m; ++j) {
				int t = (int)s[j];
				if (t >= 'a' && t <= 'z') t = t - 'a' + 10;
				else t -= '0';
				for (int k = 0; k < 4; ++k) {
					ary[i][1 + j * 4 + 3 - k] = t % 2;
					t /= 2;
				}
			}
		}
		m *= 4;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (ary[i][j] == 0 && v[i][j] == 0) {
					dfs1(i, j, keyv++);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (!v[i][j] && ary[i][j] == 1) {
					memset(r, 0, sizeof(r));
					cnt = 0;
					dfs2(i, j, keyv++);
					if (cnt == 0) ++res[5]; //W
					if (cnt == 1) ++res[0]; //A
					if (cnt == 2) ++res[3]; //K
					if (cnt == 3) ++res[2]; //J
					if (cnt == 4) ++res[4]; //S
					if (cnt == 5) ++res[1]; //D
				}
			}
		}
		cout << "Case " << tc++ << ": ";
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < res[i]; ++j) {
				cout << ac[i];
			}
		}
		cout << "\n";
	}



	return 0;
}