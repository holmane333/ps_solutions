#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, v[1010], t, res, idx;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		++v[t];
		res += t;
	}
	for (int i = 0; i <= n; ++i) {
		if (v[idx] * idx < v[i] * i) idx = i;
	}
	cout << res + v[idx] * idx << "\n";
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < v[i]; ++j) {
			cout << i << " ";
		}
	}
	cout << "\n";


	return 0;
}
