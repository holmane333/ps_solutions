#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, h;
    cin >> n >> h;

    vector<pair<ll, ll>> l;

    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        l.emplace_back(a, 1);
        l.emplace_back(b, -1);
    }

    sort(l.begin(), l.end(), [](const pair<ll, ll>& x, const pair<ll, ll>& y) {
        if (x.first == y.first) return x.second > y.second;
        return x.first < y.first;
        });

    vector<ll> r;
    r.push_back(0);
    if (n == 0) {
        r.push_back(h);
    }
    else {
        if (l[0].first != 0) {
            r.push_back(l[0].first - 1);
        }

        ll cnt = 1;
        for (int i = 1; i < n * 2; ++i) {
            if (l[i].second == 1) {
                if (cnt == 0LL) {
                    r.push_back(l[i].first - l[i - 1].first - 1);
                }
            }
            cnt += l[i].second;
        }

        if (l.back().first != h) {
            r.push_back(h - l.back().first);
        }
    }

    sort(r.begin(), r.end());
    vector<ll> rr = r;
    for (size_t i = 1; i < rr.size(); ++i) {
        rr[i] += rr[i - 1];
    }

    int q;
    cin >> q;

    while (q--) {
        ll t;
        cin >> t;

        int left = 1, right = r.size() - 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (r[mid] < t) {
                left = mid;
            }
            else {
                right = mid;
            }
        }

        if (r[left] >= t) right = left;

        if (r[right] >= t) {
            long long ans = rr.back() - rr[right - 1] - 1LL * (r.size() - right) * (t - 1);
            cout << ans << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}