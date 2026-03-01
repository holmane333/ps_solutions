#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	int u, v, t;
};

int n, m;
vector<int> parent;
vector<node> a;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionFind(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

bool cmp(node x, node y) {
	return (x.t < y.t);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	a.resize(m);
	parent.resize(100010);
	for (int i = 0; i < 100010; ++i) parent[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> a[i].u >> a[i].v >> a[i].t;
	}
	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < m; ++i) {
		if (i + 1 != a[i].t || getParent(a[i].u) == getParent(a[i].v)) {
			cout << i + 1 << "\n";
			return 0;
		}
		unionFind(a[i].u, a[i].v);
	}

	cout << n << "\n";
	return 0;
}
