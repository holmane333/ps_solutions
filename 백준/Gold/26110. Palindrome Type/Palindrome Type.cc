#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char w[100010];
int n;

int DP(int l, int r, int t) {
	if (l >= r) return 0;
	if (t > 3) return 1e9;
	if (w[l] == w[r]) return DP(l + 1, r - 1, t);
	int a = min(DP(l + 1, r, t + 1), DP(l, r - 1, t + 1)) + 1;
	if (a > 3) return (int)1e9;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> w;
	n = strlen(w);

	int d = DP(0, n - 1, 0);
	if (d <= 3) cout << d << '\n';
	else cout << -1 << '\n';
	
	return 0;
}