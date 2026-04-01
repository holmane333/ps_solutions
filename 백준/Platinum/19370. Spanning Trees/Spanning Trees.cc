#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, path[10010][2];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;

	if (n / 2 < k) {
		cout << -1 << '\n';
		return 0;
	}

	int temp = 0, prev = 0, idx = 0;
	bool c = true;
	for (int j = n / 2 + 1; j >= 1; --j) {
		if (j == n / 2 + 1 && !(n % 2)) continue;
		if (j == n / 2 + 1 && n % 2) {
			if (c) temp += j - 1;
			else temp -= j - 1;
		}
		else {
			if (c) temp += j;
			else temp -= j;
		}
		path[idx][0] = prev;
		path[idx++][1] = temp % n;
		prev = temp;
		if (j == n / 2 && !(n % 2)) continue;
		if (j == n / 2 + 1 && (n % 2)) continue;
		c = !c;
	}
	
	temp = 0, prev = 0, c = true;
	for (int j = n / 2 - 1; j >= 1; --j) {
		if (c) temp += j;
		else temp -= j;
		path[idx][0] = prev;
		path[idx++][1] = temp % n;
		prev = temp;
		c = !c;
	}

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < idx; ++j) {
			cout << (path[j][0] + i) % n + 1 << ' ' << (path[j][1] + i) % n + 1 << '\n';
		}
		cout << '\n';
	}

	return 0;
}