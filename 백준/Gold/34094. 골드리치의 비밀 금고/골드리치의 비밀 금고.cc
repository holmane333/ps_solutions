#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n, t;
    vector<ll> arr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    if (arr.back() == 0LL) {
        cout << 0 << '\n';
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        return 0;
    }

    ll res = 0LL;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == res) ++res;
        else if (arr[i] > res) break;
    }

    cout << res + 1 << '\n';

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}