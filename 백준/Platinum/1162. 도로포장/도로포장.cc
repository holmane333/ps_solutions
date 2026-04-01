#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k, a, b;
ll c, d[10010][30];
vector<vector<pair<int, ll>>> r;

struct node {
	ll c;
	int idx, k;

	bool operator<(const node& t) const {
		return c > t.c;
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> k;
	r.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		r[a].push_back(make_pair(b, c));
		r[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i < 10010; ++i) {
		for (int j = 0; j < 30; ++j) {
			d[i][j] = (ll)1e12;
		}
	}
	priority_queue<node> pq;
	pq.push({0, 1, 0});

	while (!pq.empty()) {
		node a = pq.top();
		//cout << a.c << " " << a.idx << " " << a.k << "\n";
		pq.pop();
		
		if (d[a.idx][a.k] < a.c) continue;
		for (int i = 0; i < r[a.idx].size(); ++i) {
			if (d[r[a.idx][i].first][a.k] > a.c + r[a.idx][i].second) {
				//cout << a.c << " " << a.idx << " " << a.k << " " << r[a.idx][i].first << " " << "c1" << "\n";
				pq.push({ a.c + r[a.idx][i].second, r[a.idx][i].first, a.k });
				d[r[a.idx][i].first][a.k] = a.c + r[a.idx][i].second;
			}

			//if (a.idx == 1) cout << r[a.idx][i].first << " " << a.k << " " << k << " " << d[a.idx][a.k + 1] << " " << a.c << "\n";
			if (a.k < k && d[r[a.idx][i].first][a.k + 1] > a.c) {
				//cout << a.c << " " << a.idx << " " << a.k << " " << r[a.idx][i].first << " " << "c2" << "\n";
				pq.push({ a.c, r[a.idx][i].first, a.k + 1 });
				d[r[a.idx][i].first][a.k + 1] = a.c;
			}
		}
	}

	ll res = (ll)1e12;
	for (int i = 0; i < 30; ++i) {
		//cout << d[n][i] << "\n";
		res = min(res, d[n][i]);
	}
	cout << res << "\n";
	return 0;
}