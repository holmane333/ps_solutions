#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, res = 0;
double a, b, c, d;
vector<pair<double, double>> l;
vector<double> r;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c >> d;
		l.push_back(make_pair(b / a, d / c));
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		r.push_back(b / a);
	}
	sort(r.begin(), r.end());
	for (int i = 0; i < n; ++i) {
		a = l[i].first;
		b = l[i].second;
		if (a > b) {
			c = a;
			a = b;
			b = c;
		}

		vector<double>::iterator i1, i2;
		i1 = upper_bound(r.begin(), r.end(), b);
		i2 = lower_bound(r.begin(), r.end(), a);
		if (i1 - i2 > 0) ++res;
	}

	cout << n - res << "\n";
	return 0;
}
