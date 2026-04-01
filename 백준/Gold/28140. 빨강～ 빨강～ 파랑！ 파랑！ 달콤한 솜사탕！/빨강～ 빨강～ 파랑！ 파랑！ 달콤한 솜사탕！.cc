#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, a, b;
string s;
vector<int> v1, v2, res;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> q;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			v1.push_back(i);
		}
		if (s[i] == 'B') {
			v2.push_back(i);
		}
	}

	while (q--) {
		cin >> a >> b;
		if (v1.size() < 2 || v2.size() < 2) {
			cout << -1 << "\n";
			continue;
		}
		res.clear();
		vector<int>::iterator it1, it2;
		it1 = lower_bound(v1.begin(), v1.end(), a);
		if (it1 - v1.begin() >= v1.size() - 1) {
			cout << -1 << "\n";
			continue;
		}
		
		res.push_back(*it1);
		res.push_back(*(it1 + 1));
		
		it2 = upper_bound(v2.begin(), v2.end(), *(it1 + 1));
		if (it2 - v2.begin() >= v2.size() - 1 || *(it2 + 1) > b) {
			cout << -1 << "\n";
			continue;
		}

		res.push_back(*it2);
		res.push_back(*(it2 + 1));
		
		for (int i = 0; i < res.size(); ++i) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}


	return 0;
}
