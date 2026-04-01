#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> a;
vector<pair<int, int>> res;
vector<int> l;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	a.resize(n + 1);

	for (int i = n - 1; i >= 0; --i) {
		cin >> a[i];
	}
	
	int prev = 1, idx = 2;
	l.push_back(1);
	for (int i = 0; i < n; ++i) {
		if (!i) {
			if (a[i] == 1) continue;
			if (a[i] == 2) {
				prev = 2;
				idx = 3;
				l.push_back(2);
				res.push_back(make_pair(1, 2));
				continue;
			}
			cout << -1 << '\n';
			return 0;
		}
		if (a[i] < prev || a[i] == 1) {
			cout << -1 << '\n';
			return 0;
		}
		vector<int> t;
		for (int j = 0; j < a[i]; ++j) {
			res.push_back(make_pair(l[j % prev], idx));
			t.push_back(idx++);
		}
		prev = a[i];
		l = t;
	}

	cout << res.size() + 1 << "\n";
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << " " << res[i].second << "\n";
	}
	return 0;
}