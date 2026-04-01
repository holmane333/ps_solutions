#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[1010], cnt, di[100010], idx, stone[100010];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt += a[i];
	}
	
	for (int i = 1; i <= (int)sqrt(cnt); ++i) {
		if (!(cnt % i)) {
			di[idx++] = i;
			di[idx++] = cnt / i;
		}
	}
	
	sort(di, di + idx);
	
	int temp, c;
	for (int i = idx - 1; i >= 0; --i) {
		temp = di[i];
		c = 0;
		for (int j = 0; j < n; ++j) {
			if (temp != di[i]) 
				++c;
			temp = (temp - a[j]) % di[i];
			if (temp <= 0) temp += di[i];
		}
		stone[i] = c;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = idx - 1; j >= 0; --j) {
			if (stone[j] <= i) {
				cout << di[j] << ' ';
				break;
			}
		}
	}

	cout << '\n';
	return 0;
}