#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[2010][2010] = { 0, }, pre[2010][2010] = { 0, }, res[2010][2010] = { 0, }, n, m;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	int i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			cin >> a[i][j];
			a[i][j] *= -1;
		}
	}
	
	if (m == 1) {
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		return 0;
	}
	for (i = 1; i <= n - m + 1; ++i) {
		for (j = 1; j <= n - m + 1; ++j) {
			res[i + m / 2][j + m / 2] = a[i][j] - pre[i + m - 1][j + m - 2] - pre[i + m - 2][j + m - 1] + pre[i + m - 2][j + m - 2] + pre[i + m - 1][j - 1] + pre[i - 1][j + m - 1] - pre[i - 1][j - 1];
			pre[i + m - 1][j + m - 1] = pre[i + m - 1][j + m - 2] + pre[i + m - 2][j + m - 1] - pre[i + m - 2][j + m - 2] + res[i + m / 2][j + m / 2];
		}
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}