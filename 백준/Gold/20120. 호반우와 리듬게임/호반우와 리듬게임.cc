#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

ll n, a[10101];
ll dp[1010][1010][3];
bool chk[1010][1010][3];

ll f(int i, int j, int k){
    ll &res = dp[i][j][k];
    if(chk[i][j][k]) return res;
    chk[i][j][k] = true;
    if(i == n + 1) return res = 0;
    res = f(i+1, j+1, 0) + a[i]*j;
    if(k < 2) res = max(res, f(i+1, 1, k+1));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; for(int i=1; i<=n; i++) cin >> a[i];
    ll res = f(1, 1, 0);
    if(n >= 3) res = max(res, 0ll);
    cout << res;
}