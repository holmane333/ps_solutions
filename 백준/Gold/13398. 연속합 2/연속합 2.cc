#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, dp0 = (int)- 2e9, dp1 = (int)- 2e9, res = (int)- 2e9;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a;
		dp1 = max(dp1 + a, dp0);
		dp0 = max(dp0 + a, a);
		res = max(res, max(dp0, dp1));
	}
	cout << res << '\n';
	return 0;
}