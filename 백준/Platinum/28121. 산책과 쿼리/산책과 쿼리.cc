#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, a, b;
vector<int> parent, v;

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a, v[a] += v[b];
	else if (a > b) parent[a] = b, v[b] += v[a];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> q;
	parent.resize(n * 2 + 1);
	for (int i = 0; i <= n * 2; ++i) parent[i] = i;
	v.resize(n * 2 + 1);
	for (int i = 0; i <= n * 2; ++i) v[i] = 1;
	
	int res = 0;
	while (q--) {
		cin >> a >> b;
		int t1 = (getParent(a) == getParent(a + n)), t2 = (getParent(b) == getParent(b + n));
		int prevt1 = v[getParent(a)], prevt2 = v[getParent(b)];
		unionFind(a, b + n);
		unionFind(a + n, b);
		if (!t1 && getParent(a) == getParent(a + n)) {
			res += prevt1;
		}
		else if (!t2 && getParent(b) == getParent(b + n)) {
			res += prevt2;
		}
		cout << res << "\n";
	}
	
	return 0;
}
