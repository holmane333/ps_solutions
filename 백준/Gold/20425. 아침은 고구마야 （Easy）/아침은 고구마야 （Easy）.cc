#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, x, y, c, v[1000011];
vector<vector<int>> a;
ll res = 0LL;

void dfs(int d, int pre) {
    for (int i = 0; i < a[d].size(); ++i) {
        if (!v[a[d][i]]) {
            v[a[d][i]] = v[d] + 1;
            dfs(a[d][i], d);
        }
        else {
            if (a[d][i] == pre || v[d] <= v[a[d][i]]) continue;
            ll t = (abs)((ll)(v[d] + 1) - (ll)v[a[d][i]]);
            res += t * t;
            //cout << v[d] + 1 << " " << v[a[d][i]] << " " << res << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> c;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    v[0] = v[1] = 1;
    dfs(1, 0);

    cout << res << "\n";

    return 0;
}
