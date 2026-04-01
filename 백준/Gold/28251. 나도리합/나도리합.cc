#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b, res;
vector<int> p;
vector<ll> ary, s, v;

int getparent(int a) {
	if (a == p[a]) return a;
	return p[a] = getparent(p[a]);
}

void unionfind(int a, int b) {
	int aa = getparent(a);
	int bb = getparent(b);
	if (aa != bb) {
		v[aa] += s[aa] * s[bb] + v[bb];
		s[aa] += s[bb];
		p[bb] = aa;
	}
	cout << v[aa] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	p.resize(200010);
	ary.resize(200010);
	s.resize(200010);
	v.resize(200010);
	for (int i = 0; i <= 200000; ++i) p[i] = i;
	for (int i = 1; i <= n; ++i) {
		cin >> ary[i];
		s[i] = ary[i];
		v[i] = 0LL;
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		unionfind(a, b);
	}
	return 0;
}