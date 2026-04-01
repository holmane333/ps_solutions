#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k, a, b;
ll p[500010][3], s[500010], res, cnt, nowp;
queue<ll> q;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i) {
		cin >> p[i][0];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> p[i][1];
	}
	for (int i = 0; i < k; ++i) q.push(0);

	for (int i = 1; i <= n; ++i) {
		s[i] += max(0LL, s[i - 1] - nowp);
		cnt = 0;
		if (p[i][0] + s[i] < p[i][1]) {
			cnt = (p[i][1] - (p[i][0] + s[i])) / k + ((p[i][1] - (p[i][0] + s[i])) % k > 0);
		}
		res += cnt;
		nowp += cnt - q.front();
		q.pop();
		q.push(cnt);
		s[i] += cnt * k;
	}
	
	cout << res << '\n';
	return 0;
}