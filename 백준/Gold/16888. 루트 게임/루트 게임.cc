#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc, dp[1000010], t;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	int i, j;
	
	for (i = 1; i * i <= 1000000; ++i) {
		dp[i * i] = 1;
	}
	for (i = 0; i < 1000010; ++i) {
		if (!dp[i]) {
			for (int j = 1; i + j * j <= 1000000; ++j) {
				dp[i + j * j] = 1;
			}
		}
	}

	cin >> tc;
	while (tc--) {
		cin >> t;
		if (dp[t]) cout << "koosaga" << '\n';
		else cout << "cubelover" << '\n';
	}

	return 0;
}