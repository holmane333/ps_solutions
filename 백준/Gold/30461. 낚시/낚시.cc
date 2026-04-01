#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q, a, b;
ll p[2010][2010], l;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> l;
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j] + l;
            if (i >= 2) p[i][j] -= p[i - 2][j - 1];
        }
    }
    
    while (q--) {
        cin >> a >> b;
        cout << p[a][b] << "\n";
    }
    
    return 0;
}
