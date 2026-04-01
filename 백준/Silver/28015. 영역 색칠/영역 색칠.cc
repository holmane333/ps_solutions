#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, r, b, p, res;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		r = 0, b = 0, p = 0;
		for (int j = 0; j < m; ++j) {
			cin >> a;
			if (a != p) {
				if (a == 1) ++r;
				if (a == 2) ++b;
				p = a;
			}
			if (!a) {
				if (!r && !b) continue;
				res += min(r, b) + 1;
				r = 0, b = 0;
			}
		}
		if (!r && !b) continue;
		res += min(r, b) + 1;
	}

	cout << res << "\n";
	return 0;
}
