#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

int p(int x, int y, int c) {
	if (x >= y) return 0;
	if (s[x] == s[y]) return (p(x + 1, y - 1, c));
	else {
		if (c) return 2;
		else {
			if (!p(x + 1, y, 1) || !p(x, y - 1, 1)) return 1;
			return 2;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> s;
		cout << p(0, s.size() - 1, 0) << "\n";
	}

	return 0;
}