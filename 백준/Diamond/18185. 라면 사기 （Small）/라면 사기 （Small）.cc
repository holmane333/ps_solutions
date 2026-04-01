#include <bits/stdc++.h>
using namespace std;

vector <long long> a;
long long n, res = 0LL;

void buy(int index, int len, long long min_value) {
    for (int i = index; i < index + len; ++i) a[i] -= min_value;
    res += min_value * ((len - 1) * 2 + 3);
}

int main() {
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    cin >> n;
    a.resize(n + 3);
    for (int i = 0; i < n; ++i) cin >> a[i];
    a[n] = a[n + 1] = 0LL;

    for (int i = 0; i < n; ++i) {
        if (a[i + 1] > a[i + 2]) buy(i, 2, min(a[i], a[i + 1] - a[i + 2]));
        buy(i, 3, min(min(a[i], a[i + 1]), a[i + 2]));
        buy(i, 2, min(a[i], a[i + 1]));
        buy(i, 1, a[i]);
    }

    cout << res;
}
