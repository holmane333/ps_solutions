#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<int> a;
int v[100010];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	a[0] %= k;
	++v[a[0]];
	for (int i = 1; i < n; ++i) {
		a[i] = (a[i] + a[i - 1]) % k;
		++v[a[i]];
	}

	int res = 0;
	for (int i = 0; i <= k; ++i) {
		res = max(res, v[i]);
	}
	
	cout << res << "\n";
	return 0;
}
