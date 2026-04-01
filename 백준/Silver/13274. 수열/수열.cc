#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100010] = {0, }, b[100010] = {0, }, x;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int i, n, k, l, r;
	cin >> n >> k;
	for (i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	while (k--) {
		cin >> l >> r >> x;
		--l;
		--r;
		int s1 = 0, s2 = l, idx = 0;
		while (s1 < n || s2 < r + 1) {
			if (s1 == l) s1 = r + 1;
			if (s1 >= n || (s2 < r + 1 && a[s1] > a[s2] + x)) {
				b[idx++] = a[s2++] + x;
			}
			else {
				b[idx++] = a[s1++];
			}
		}
		for (i = 0; i < n; ++i) {
			a[i] = b[i];
		}
	}
	for (i = 0; i < n; ++i) {
		cout << b[i] << ' ';
	}
	cout << '\n';
	return 0;
}