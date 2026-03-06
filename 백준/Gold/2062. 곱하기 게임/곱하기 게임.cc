#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc, k;
double x, a[10], minv, maxv;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> tc;
	while (tc--) {
		priority_queue<pair<double, double>, vector<pair<double, double>>, greater<pair<double, double>>> pq;
		cin >> x >> k;
		for (int i = 0; i < k; ++i) {
			cin >> a[i];
			a[i] = 1.0 / a[i];
			if (i == 0) minv = maxv = a[i];
			minv = min(minv, a[i]);
			maxv = max(maxv, a[i]);
			pq.push({ 1.0, a[i] });
		}
		double e = 1.0;
		while (!pq.empty()) {
			while (!pq.empty() && pq.top().first <= e) {
				e = max(e, pq.top().second);
				pq.pop();
			}
			if (x <= e) {
				cout << "Nils\n";
				break;
			}
			double s = e;
			if (pq.empty()) {
				e = e * minv;
			}
			else {
				e = min(e * minv, pq.top().first);
			}

			for (int i = 0; i < k; ++i) {
				pq.push({ s * a[i], e * a[i] });
			}

			if (x <= e) {
				cout << "Mikael\n";
				break;
			}
		}
	}


	return 0;
}