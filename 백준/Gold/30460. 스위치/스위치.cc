#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[200010], l[200010];

ll DP(int idx) {
    if (idx < 0) return 0LL;
    if (dp[idx] != -1LL) return dp[idx];

    dp[idx] = 0LL;
    if (idx >= 2) dp[idx] = max(DP(idx - 3) + (l[idx] + l[idx - 1] + l[idx - 2]) * 2LL, DP(idx - 1) + l[idx]);
    else dp[idx] = DP(idx - 1) + l[idx];
    if (n - 1 == idx) dp[idx] = max(max(dp[idx], DP(idx - 1) + l[idx] * 2LL), DP(idx - 2) + (l[idx] + l[idx - 1]) * 2LL);
    return dp[idx];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0 ; i < n; ++i) {
        cin >> l[i];
    }

    cout << DP(n - 1);
    return 0;
}
