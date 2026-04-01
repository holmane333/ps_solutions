#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n, t, res;
    unordered_map<ll, ll> m;

    cin >> n;
    res = (n * (n + 1)) / 2;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        ++m[t];
        res -= m[t];
    }

    cout << res + 1;
    
}