#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, dp[3010], res[3010];
vector<vector<int>> ary;
vector<int> ans;

int DP(int idx) {
	if (idx >= n) return 0;
	if (dp[idx] != -1) return dp[idx];
	
	dp[idx] = 1000000000;

	int temp;
	for (int i = idx + 1; i <= n; ++i) {
		// cout << idx << " " << i << " " << (i - idx - 1) * (i - idx) / 2 << " " << -(ary[i][i] - ary[i][idx] - ary[idx][i] + ary[idx][idx]) / 2 << " " << (ary[i][idx] - ary[idx][idx]) << "\n";
		temp = DP(i) + ((i - idx - 1) * (i - idx) / 2 - (ary[i][i] - ary[i][idx] - ary[idx][i] + ary[idx][idx]) / 2) + (ary[i][idx] - ary[idx][idx]);
		if (dp[idx] > temp) {
			dp[idx] = temp; // idx + 1 ~ i까지 묶었을 때
			res[idx] = i;
		}
	}
	
	// cout << idx << " " << dp[idx] << "\n";
	return dp[idx];
}

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	memset(dp, -1, sizeof(dp));
	cin >> n;
	ary.resize(n + 1);
	for (int i = 0; i <= n; ++i) ary[i].resize(n + 1);
	
	int a;
	for (int i = 1; i <= n; ++i) {
		while (1) {
			cin >> a;
			if (!a)
				break;

			ary[i][a] = 1;
			ary[a][i] = 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ary[i][j] = ary[i - 1][j] + ary[i][j - 1] - ary[i - 1][j - 1] + ary[i][j];
		}
	}
	/*
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			cout << ary[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
	*/
	cout << DP(0) << "\n";
	int prev = 0, temp = 0;
	while (temp < n) {
		temp = res[temp];
		// cout << temp - prev << " ";
		ans.push_back(temp - prev);
		prev = temp;
	}
	cout << ans.size() << " ";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}