#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	int first;
	int second;
	ll value;
};

bool cmp(Node a, Node b) {
	return (a.value > b.value);
}

vector<Node> t;
int n, m, s;
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

ll dfs(int x) {
	ll cnt = 0LL;
	for (int i = 0; i < edge[x].size(); ++i) {
		if (!v[edge[x][i].first]) {
			v[edge[x][i].first] = 1;
			cnt = max(cnt, dfs(edge[x][i].first) + edge[x][i].second);
			r += edge[x][i].second;
			v[edge[x][i].first] = 0;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	parent.resize(n + 1);
	v.resize(n + 1);
	t.resize(m);
	edge.resize(n + 1);
	for (int i = 0; i <= n; ++i) parent[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> t[i].first >> t[i].second >> t[i].value;
	}
	cin >> s;

	sort(t.begin(), t.end(), cmp);
	for (int i = 0; i < m; ++i) {
		if (getParent(t[i].first) != getParent(t[i].second)) {
			unionFind(t[i].first, t[i].second);
			edge[t[i].first].push_back(make_pair(t[i].second, t[i].value));
			edge[t[i].second].push_back(make_pair(t[i].first, t[i].value));
		}
	}

	v[s] = 1;
	ll res = dfs(s);
	cout << r * 2 - res << "\n";

	return 0;
}
