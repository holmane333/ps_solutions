#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc, n, a, ary[110], cnt;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			ary[a] = i;
		}
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (ary[j] < ary[i]) ++cnt;
			}
		}
		if (cnt % 2) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}