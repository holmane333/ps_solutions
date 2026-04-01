#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n, res, temp, m = 0;
    cin >> n;
    res = n - 1;

    for (ll i = 1; i < n; ++i) {
        temp = (n / 2) * (n / 2) - i * i;
        if(temp <= 0) break;
        ll sq_temp = sqrt(temp);
        if (sq_temp * sq_temp == temp) ++m;
    }

    res -= m;
    res *= 4;

    cout << res;

    return 0;
}