#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x, y, z;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	
	if (n == 1) {
		cout << a[0] << "\n";
		return 0;
	}
	if (n == 2) {
		cout << a[0] + a[1] - 1 << "\n";
		return 0;
	}
	x = 0;
	y = n / 3 + (n % 3 ? 1 : 0);
	z = (n / 3) * 2 + (n % 3);

	cout << a[x] + a[y] + a[z] - 3 << "\n";
	return 0;
}
