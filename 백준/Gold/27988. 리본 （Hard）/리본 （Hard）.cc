#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[4], res[4], m[1000010][4];
char t[4];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> m[i][0];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> m[i][1];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		if (t[0] == 'R') m[i][2] = 0;
		else if (t[0] == 'Y') m[i][2] = 1;
		else m[i][2] = 2;
	}

	for (int i = 0; i < 3; ++i) a[i] = (ll)-1e10, res[i] = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (m[i][2] == j) continue;
			if (m[i][0] - m[i][1] <= a[j]) {
				cout << "YES\n";
				cout << res[j] << ' ' << i << '\n';
				return 0;
			}
		}
		if (a[m[i][2]] < m[i][0] + m[i][1]) {
			a[m[i][2]] = m[i][0] + m[i][1];
			res[m[i][2]] = i;
		}
	}
	cout << "NO\n";
	return 0;
}