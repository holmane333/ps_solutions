#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

struct node {
	int v;
	int l;
	int r;
};

int n, m;
vector<node> e;
vector<int> s;

ll dp[2020][2020];

void dfs(int x) {
	if (x == -1) return;
	
	dfs(e[x].l);
	s.push_back(e[x].v);
	dfs(e[x].r);
}

void p() {
	dp[0][0] = 1LL;
	dp[1][0] = 1LL;
	dp[1][1] = 1LL;
	for (int i = 2; i <= 2000; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0) dp[i][0] = 1LL;
			else if (j == i) dp[i][j] = 1LL;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
}
/*
ll comb(ll x, ll y) {
	if (y == 0 || x == y) return 1LL;
	ll k1 = comb(x - 1, y - 1), k2 = comb(x - 1, y);
	return ((k1 + k2) % MOD);
}*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	e.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> e[i].v >> e[i].l >> e[i].r;
	}

	dfs(1);
	p();
	int prev = 0, len = 0;
	ll res = 1LL;
	for (int i = 0; i < n; ++i) {
		if (s[i] == -1) {
			++len;
		}
		else {
			res = (res * dp[s[i] - prev - 1][len]) % MOD;
			prev = s[i];
			len = 0LL;
		}
	}
	res = (res * dp[m - prev][len]) % MOD;
	cout << res << "\n";
	return 0;
}
