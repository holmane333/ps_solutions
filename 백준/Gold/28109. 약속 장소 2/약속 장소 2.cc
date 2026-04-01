#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, res;
char s[100010];


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	cin >> s;
	--k;
	for (int i = 0; i < n; ++i) {
		if ((int)(s[i] - 'A') <= k) {
			k -= (int)(s[i] - 'A');
		}
		else {
			s[i] = (char)((int)'A' + k);
			cout << s << "\n";
			return 0;
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		if ((int)('Z' - s[i]) < k) {
			k -= (int)('Z' - s[i]);
		}
		else {
			s[i] = (char)((int)s[i] + k);
			cout << s << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
	return 0;
}
