#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, k, s, e, i;
ll a[120010] = {0LL, }, res, cnt;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> t;
	while (n--) {
		cin >> k;
		while (k--) {
			cin >> s >> e;
			++a[s];
			--a[e];
		}
	}
	
	for (i = 1; i <= 100000; ++i) {
		a[i] += a[i - 1];
	}
	res = (ll)-1e9;
	cnt = 0LL;
	s = -1;
	e = -1;
	for (i = 0; i < t; ++i) {
		cnt += a[i];
	}

	for (i = t; i <= 100000; ++i) {
		if (res < cnt) {
			res = cnt;
			s = i - t;
			e = i;
		}
		cnt += a[i];
		cnt -= a[i - t];
	}

	cout << s << ' ' << e << '\n';
	return 0;
}