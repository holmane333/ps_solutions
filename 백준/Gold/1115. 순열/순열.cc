#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, i, j, k;
int a[100] = { 0, }, v[100] = { 0, }, res, cnt, check;

void dfs(int x) {
	if (!v[x]) {
		v[x] = 1;
		dfs(a[x]);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (i = 0; i < n; ++i) {
		if (!v[i]) {
			v[i] = 1;
			dfs(a[i]);
			++cnt;
		}
	}

	if (cnt == 1) cout << 0 << '\n';
	else cout << cnt << '\n';
	return 0;
}