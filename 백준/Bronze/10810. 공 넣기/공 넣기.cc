#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, a, b, c;
    int arr[110] = {0, };

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        for (int j = a; j <= b; ++j) {
            arr[j] = c;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << ' ';
    }

    return 0;
}