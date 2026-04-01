#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	int first;
	int second;
	ll value;
};

bool cmp(Node a, Node b) {
	return (a.value < b.value);
}

vector<Node> t;
int n, m, s, a;
vector<int> parent, v;
vector<vector<pair<int, ll>>> edge;
ll r;

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> s;
	parent.resize(n + 1);
	v.resize(n + 1);
	t.resize(m);
	for (int i = 0; i <= n; ++i) parent[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> t[i].first >> t[i].second >> t[i].value;
	}
	for (int i = 0; i < n; ++i) cin >> a;

	sort(t.begin(), t.end(), cmp);
	for (int i = 0; i < m; ++i) {
		if (getParent(t[i].first) != getParent(t[i].second)) {
			unionFind(t[i].first, t[i].second);
			r += t[i].value;
		}
	}

	cout << r << "\n";
	return 0;
}
