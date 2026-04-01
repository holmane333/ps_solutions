#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b, res;
vector<int> parent;

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
	cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 0; i <= n; ++i) parent[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		unionFind(a, b);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (getParent(i) != getParent(j)) {
				unionFind(i, j);
				++res;
			}
		}
	}

	cout << res << "\n";
	return 0;
}
