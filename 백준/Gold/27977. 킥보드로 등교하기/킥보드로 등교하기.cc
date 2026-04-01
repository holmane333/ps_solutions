#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l, n, k, t;
vector<int> a;

int check(int mid) {
	vector<int>::iterator it;
	int x = l;
	for (int i = 0; i < k; ++i) {
		it = lower_bound(a.begin(), a.end(), x - mid);
		if (it == a.end()) return 0;
		x = *it;
		//cout << " " << x << " " << mid << "\n";
	}
	if (x > mid) return 0;
	//cout << " " << x << " " << mid << "\n";
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> l >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		a.push_back(t);
	}

	//a.push_back(1000000);
	int left = 1, right = l, res = l;

	while (left <= right) {
		int mid = (left + right) / 2;
		//cout << mid << "\n";
		if (check(mid)) {
			res = min(res, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << res << "\n";
	return 0;
}
