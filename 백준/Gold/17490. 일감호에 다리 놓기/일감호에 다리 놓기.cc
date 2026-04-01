#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//28016

int n, m, idx;
ll k, s[1000010], cnt[1000010], res;
pair<int, int> a[1000010];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + m);
	for (int i = 0; i < 1000010; ++i) cnt[i] = (ll)1e10;
	
	if (m <= 1) {
		cout << "YES\n";
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (i + 1 == a[idx].second) {
			++idx;
		}
		cnt[idx] = min(cnt[idx], s[i]);
	}

	if (a[m - 1].second != 1) {
		cnt[0] = min(cnt[0], cnt[idx]);
		--idx;
	}
	for (int i = 0; i <= idx; ++i) {
		res += cnt[i];
	}

	if (res <= k) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}