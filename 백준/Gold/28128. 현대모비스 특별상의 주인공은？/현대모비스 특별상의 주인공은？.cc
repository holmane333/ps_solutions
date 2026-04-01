#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<vector<string>> a;
vector<string> res;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j < m - 1 && a[i][j] == a[i][j + 1]) res.push_back(a[i][j]);
			if (j < m - 2 && (a[i][j] == a[i][j + 1] || a[i][j] == a[i][j + 2])) res.push_back(a[i][j]);
			if (j < m - 2 && a[i][j + 1] == a[i][j + 2]) res.push_back(a[i][j + 1]);
			if (i < n - 1 && a[i][j] == a[i + 1][j]) res.push_back(a[i][j]);
			if (i < n - 2 && (a[i][j] == a[i + 1][j] || a[i][j] == a[i + 2][j])) res.push_back(a[i][j]);
			if (i < n - 2 && (a[i + 1][j] == a[i + 2][j])) res.push_back(a[i + 1][j]);
		}
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); ++i) {
		if (i && res[i] == res[i - 1]) continue;
		cout << res[i] << "\n";
	}
	if (res.empty()) cout << "MANIPULATED" << "\n";
	return 0;
}
