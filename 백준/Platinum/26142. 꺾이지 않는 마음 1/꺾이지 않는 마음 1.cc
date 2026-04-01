#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a, b, dp[10010], tmp[10010];
vector<pair<ll, ll>> dr;

bool cmp(pair<ll, ll>a1, pair<ll, ll>b1) {
    if (a1.first == b1.first) return a1.second < b1.second;
    return a1.first < b1.first;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    dr.push_back(make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        dr.push_back(make_pair(a, b));
    }
    sort(dr.begin(), dr.end(), cmp);
    
    for (int i = 1; i <= n; ++i) {
        ll res = 0LL;
        if (i == 1) {
            for (int j = 1; j <= n; ++j) {
                tmp[j] = max(tmp[j - 1], dr[j].second);
                res = max(res, tmp[j]);
            }
        }
        else {
            dp[0] = 0LL;
            tmp[0] = 0LL;
            for (int j = 1; j <= n; ++j) {
                if (j <= i) dp[j] = dp[j - 1] + dr[j].first * (ll)(j - 1) + dr[j].second;
                else dp[j] = max(dp[j - 1], tmp[j - 1] + dr[j].first * (ll)(i - 1) + dr[j].second);
            }
            for (int j = 1; j <= n; ++j) {
                tmp[j] = dp[j];
                res = max(res, tmp[j]);
            }
        }
        cout << res << "\n";
    }


    return 0;
}
