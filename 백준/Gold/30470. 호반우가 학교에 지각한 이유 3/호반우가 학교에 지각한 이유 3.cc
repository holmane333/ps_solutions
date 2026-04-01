#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, b, maxv, l[500010], lenv, maxl[500010];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a == 1) {
            if (lenv) maxl[lenv - 1] = maxv;
            l[lenv++] = b;
            maxv = b;
        }
        else {
            if (!lenv) continue;
            maxv = max(0, maxv - b);
        }
    }
    if (lenv) maxl[lenv - 1] = maxv;

    ll res = 0LL;
    maxv = (int)1e9;
    for (int i = lenv - 1; i >= 0; --i) {
        maxv = min(maxv, maxl[i]);
        res += (maxv);
    }
    
    cout << res;
    return 0;
}
