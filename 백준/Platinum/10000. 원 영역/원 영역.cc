#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	ll x, r, res = 1LL;
	cin >> n;
	vector<pair<ll, ll>> circle;
	circle.resize(2 * n);
	for (int i = 0; i < n; ++i) {
		cin >> x >> r;
		circle[i * 2].first = x - r;
		circle[i * 2].second = -1;
		circle[i * 2 + 1].first = x + r;
		circle[i * 2 + 1].second = 1;
	}
	ll st[600010][2] = {0LL, }, top = 0;
	sort(circle.begin(), circle.end(), cmp);
	
	for (int i = 0; i < 2 * n; ++i) {
		if (circle[i].second == -1LL) { // 왼쪽
			if (top > 0 && circle[i].first == st[top - 1][0]) {
				if (st[top - 1][1] == 0LL) st[top - 1][1] = 1LL;
			}
			else if (top > 0) {
				st[top - 1][1] = 2LL;
			}
			else {
			}
			st[top][0] = circle[i].first;
			st[top++][1] = 0LL;
		}
		else { // 오른쪽
			if (st[top - 1][1] == 1 && st[top - 1][0] == circle[i].first) ++res;
			--top;
			if (top > 0) st[top - 1][0] = circle[i].first;
			++res;
		}
	}

	cout << res;
	return 0;
}