#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, v[1010], m, cnt;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (v[m] < 2) ++cnt;
        ++v[m];
    }
    cout << cnt;

    return 0;
}
