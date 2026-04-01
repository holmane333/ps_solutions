#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[200010], y, m, res, idx;
string t1, t2;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> t1 >> t2;
		y = stoi(t1.substr(0, 4));
		m = stoi(t1.substr(5, 7));
		//sscanf(t1, "%d-%d", &y, &m);
		++a[y * 12 + m];
		y = stoi(t2.substr(0, 4));
		m = stoi(t2.substr(5, 7));
		//sscanf(t2, "%d-%d", &y, &m);
		--a[y * 12 + m + 1];
	}
	res = 0;
	idx = 0;
	for (int i = 1; i <= 200000; ++i) {
		a[i] += a[i - 1];
		if (res < a[i]) {
			res = a[i];
			idx = i;
		}
	}
	cout << idx / 12 + (idx % 12 ? 0 : -1) << "-";
	if (idx % 12 != 0 && idx % 12 < 10) cout << "0";
	cout << idx % 12 + (idx % 12 ? 0 : 12) << "\n";
	return 0;
}