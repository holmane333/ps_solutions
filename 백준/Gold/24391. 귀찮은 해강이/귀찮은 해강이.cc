#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b, res;
int p[100010];

int getparent(int a) {
	if (a == p[a]) return a;
	return p[a] = getparent(p[a]);
}

void unionfind(int a, int b) {
	int aa = getparent(a);
	int bb = getparent(b);
	if (aa != bb) {
		p[bb] = aa;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= 100000; ++i) p[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		unionfind(a, b);
	}
	cin >> a;
	for (int i = 1; i < n; ++i) {
		cin >> b;
		if (getparent(a) != getparent(b)) ++res;
		a = b;
	}

	cout << res << '\n';
	return 0;
}