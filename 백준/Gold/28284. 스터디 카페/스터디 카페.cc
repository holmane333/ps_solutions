#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll x;
    ll s;
};

bool cmp(const node& a1, const node& a2) {
    return a1.x < a2.x;
}

int n, m;
ll maxres, minres, d[500010], d2[500010], x, y;
node ary[1000010];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    sort(d + 1, d + n + 1);
    
    for (int i = 1; i <= n; ++i) {
        d2[i] = d[n - i + 1];
        if (i) d2[i] += d2[i - 1];
        //cout << d2[i] << " ";
    }//cout << "\n";
    for (int i = 1; i <= n; ++i) d[i] += d[i - 1];// cout << d[i] << " ";;
    //cout << "\n";
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        ary[i * 2].x = x;
        ary[i * 2].s = 1LL;
        ary[i * 2 + 1].x = y + 1;
        ary[i * 2 + 1].s = -1LL;
    }

    sort(ary, ary + m * 2, cmp);
    
    //for (int i = 0; i < m * 2; ++i) cout << ary[i].x << " " << ary[i].s << " "; cout << "\n";

    int i = 1;
    ll p = ary[0].x, cnt = 1;
    while (i < m * 2) {
        while (i < m * 2 && ary[i].x == p) {
            cnt += ary[i++].s;
        }
        if (i >= m * 2) break;
        
        //cout << maxres << " " << minres << " " << cnt << "\n";
        maxres += d2[cnt] * abs(p - ary[i].x);
        minres += d[cnt] * abs(p - ary[i].x);

        p = ary[i].x;
        cnt += ary[i++].s;
    }
    
    cout << minres << " " << maxres << "\n";
    
    return 0;
}
