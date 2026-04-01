#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, i, j, k;
int a[100][100] = { 0, }, c[100] = { 0, }, v[100] = { 0, }, res, cnt, check;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j]) ++c[i];
		}
	}

	res = n - 1;
	for (i = 0; i < n; ++i) {
		cnt = 0;
		memset(v, 0, sizeof(v));
		for (j = 0; j < n; ++j) {
			if (i == j) continue;
			if (c[j] == 0) continue;
			if (c[j] > 1) ++cnt;
			else {
				check = 0;
				for (k = 0; k < m; ++k) {
					if (!v[k] && a[j][k]) {
						check = 1;
						v[k] = 1;
						break;
					}
				}
				if (!check) ++cnt;
			}
		}
		res = min(res, cnt);
	}

	cout << res << '\n';
	return 0;
}