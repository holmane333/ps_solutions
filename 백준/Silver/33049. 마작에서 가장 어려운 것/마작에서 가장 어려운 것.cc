#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, l, res1 = 0, res2 = 0;
	cin >> n >> m >> l;
	
	res1 += n / 3;
	n %= 3;
	if (n) {
		l -= 3 - n;
		++res1;
	}
	res2 += m / 4;
	m %= 4;
	if (m) {
		l -= 4 - m;
		++res2;
	}
 	if (l < 0) cout << -1;
	else {
		int flag = 0;
		for (int i = 0; i <= l / 3; ++i) {
			if (!((l - i * 3) % 4)) {
				res1 += i;
				res2 += (l - i * 3) / 4;
				flag = 1;
				break;
			}
		}
		if (flag) cout << res1 << " " << res2;
		else cout << -1;
	}


	return 0;
}