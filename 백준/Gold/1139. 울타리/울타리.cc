#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
double a[20] = { 0, }, dp[200010];

double area(int x, int y, int z) {
	if (a[x] + a[y] <= a[z]) return 0.0;
	double p = (a[x] + a[y] + a[z]) / 2;
	return sqrt(p * (p - a[x]) * (p - a[y]) * (p - a[z]));
}

double DP(int b) {
	if (dp[b] != -1.0) return dp[b];
	dp[b] = 0.0;
	int t;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				t = (1 << i) + (1 << j) + (1 << k);
				if (!(b & t)) {
					dp[b] = max(dp[b], DP(b | t) + area(i, j, k));
				}
			}
		}
	}
	return dp[b];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < 200010; ++i) dp[i] = -1.0;
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << DP(0) << '\n';
	
	return 0;
}