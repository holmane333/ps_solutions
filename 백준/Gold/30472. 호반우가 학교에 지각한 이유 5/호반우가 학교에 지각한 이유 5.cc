#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll res;
vector<pair<ll, pair<ll, ll>>> l;

bool cmp(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b) {
    if (a.first == b.first) return a.second.first > b.second.first;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    l.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i].second.first >> l[i].second.second;
        l[i].first = l[i].second.second - l[i].second.first;
    }
    sort(l.begin(), l.end(), cmp);
    /*
    for (int i = 0; i < n; ++i) {
        cout << l[i].second.first << " " << l[i].second.second << "\n";
    }*/

    ll tmp = 0LL, lowv = 0LL;
    res = 0LL;
    for (int i = 0; i < n; ++i) {
        tmp += l[i].second.first;
        res += tmp;
        tmp -= l[i].second.second;
        lowv = min(lowv, tmp);
    }
    res += -1 * lowv * n;
    cout << res;
    return 0;
}
