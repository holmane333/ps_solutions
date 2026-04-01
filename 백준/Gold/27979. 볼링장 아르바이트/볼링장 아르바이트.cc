#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, t, res = 0;
vector<int> a, b;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		a.push_back(t);
		b.push_back(t);
	}
	sort(b.begin(), b.end());

	t = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] != b[t]) ++res;
		else --t;
	}
	cout << res << "\n";
	return 0;
}
