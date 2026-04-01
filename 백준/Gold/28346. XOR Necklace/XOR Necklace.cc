#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tc, n, cnt, s;
ll d[510], res[510], t;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		
		cnt = 0;
		t = 0;
		s = 0;
		d[n] = d[0];
		res[0] = d[0];
		cnt = 1;
		for (int i = 1; i < n; ++i) {
			if ((res[cnt - 1] ^ d[i]) + (d[i] ^ d[i + 1]) < (res[cnt - 1] ^ d[i + 1])) {
				
			}
			else {
				res[cnt++] = d[i];
			}
		}
		if (cnt >= 3) {
			if ((res[0] ^ res[1]) + (res[cnt - 1] ^ res[0]) < (res[1] ^ res[cnt - 1])) {
				s = 1;
			}
		}
		//cout << cnt << " " << s << "\n";
		res[cnt] = res[s];
		for (int i = s; i < cnt; ++i) {
			t += res[i] ^ res[i + 1];
		}
		cout << t << "\n";
	}

	return 0;
}