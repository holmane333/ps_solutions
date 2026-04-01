#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
int m, t1, t2, root[200010], s[200010];

int getParent(int a) {
    if (a == root[a]) return a;
    return root[a] = getParent(root[a]);
}

int unionFind(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a != b) {
        if (a > b) {
            root[a] = b;
            s[b] += s[a];
        }
        else {
            root[b] = a;
            s[a] += s[b];
        }
        return 1;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i <= 200000; ++i) root[i] = i;
    for (int i = 0; i <= 200000; ++i) s[i] = 1;

    for (int i = 0; i < m; ++i) {
        cin >> t1 >> t2;
        ll tmp1 = s[getParent(t1)];
        ll tmp2 = s[getParent(t2)];
        if (unionFind(t1, t2)) {
            n -= tmp1 * (tmp1 + 1) / 2;
            n -= tmp2 * (tmp2 + 1) / 2;
            n += (tmp1 + tmp2) * (tmp1 + tmp2 + 1) / 2;
        }
        cout << n << "\n";
    }

    return 0;
}
