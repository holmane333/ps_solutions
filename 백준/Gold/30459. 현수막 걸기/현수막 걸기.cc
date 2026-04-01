#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, r, p[2010], g[40010], maxv;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m >> r;
    r *= 2;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> g[i];
    }

    sort(g, g + m);
    maxv = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(p[i] - p[j]) > r) continue;

            int t = r / (abs(p[i] - p[j]));
            if (t < g[0]) continue;
            int left = 0, right = m - 1, mid, res = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                if (g[mid] == t) {
                    res = g[mid];
                    break;
                }
                if (g[mid] < t) {
                    left = mid + 1;
                    res = max(g[mid], res);
                }
                else right = mid - 1;
            }
            maxv = max(maxv, abs(p[i] - p[j]) * res);
        }
    }

    if (!maxv) cout << -1;
    else {
        cout << fixed;
        cout.precision(1);
        cout << (double)maxv / 2.0;
    }
    return 0;
}
